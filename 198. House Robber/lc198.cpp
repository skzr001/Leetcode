/*
The DP problem resemble Tree Dynamic Programming solving Independent Set. But much easier.
dp[i] represent the optimal result from num[0] to num[i].
At last, we return dp[n-1].
Transition formula: dp[i]=max(dp[i-1], dp[i-2]+num[i]).
DP[0]=0;
DP[1]=num[0];

*/
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n=nums.size();
        vector<int> dp(n,0);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
};