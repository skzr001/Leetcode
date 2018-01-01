class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size):average_size(size),sum(0){

    }

    double next(int val) {
        sum+=val;
        q.push(val);
        int queue_size=(int)q.size();
        if(queue_size<=average_size) return sum/queue_size;
        else{
            sum-=q.front();
            q.pop();
            return sum/average_size;
        }
    }
private:
    queue<int> q;
    int average_size;
    double sum;
};