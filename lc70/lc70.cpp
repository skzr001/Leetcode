class Solution {
public:
    int climbStairs(int n) \{//DP approach\
        vector<int> step(n,0);
        step[0]=1;
        step[1]=2;
        for(int i=2;i<n;i++) step[i]=step[i-1]+step[i-2];
        return step[n-1];
    }
};}