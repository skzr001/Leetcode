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
