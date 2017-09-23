>   很直观的sliding window题目，我们维护一个sum来记录从sliding window的first到last所剩余的油量，同时维护一个count变量的记录这个sliding window
的大小。

>   至于更新，sum+gas[i]-[cost]>0则意味着可以到达下一个节点i+1。
>   first指针的更新，当sum<0时，意味着last指针无法到达下一个节点，此时要更新first指针，同时要更新sum和count，直到找到一个first值使得sum>=0
<code>
class Solution {
    /*
    Follow up:
    If the tank is within limited size V.
    What does the solution change.
    */
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const int N=gas.size();
        int first=0,last=0,sum=0;
        vector<int> balance(N,0);
        for(int i=0;i<N;i++) balance[i]=gas[i]-cost[i];
        if(balance.size()==1) return balance[0]>=0?0:-1;
        for(int cnt=0;cnt<N;){
            
            while(sum<0){
                sum-=balance[first];
                if(--cnt<0) return -1;
                first++;
            }
            sum+=balance[last];
            last+1<N?last=last+1:last=(last+1)%N;
            if(++cnt==N) break;
        }
        return sum>=0?first:-1;
    }
};
</code>
