/*
dp[i][j]:cost from range[i...j].
return dp[1][n];
dp[i][j]=guess+max(dp[i][guess-1],dp[guess+1][j]);
Initialization:dp[i][i]=i;

*/
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=1;j--){
                int val_min=INT_MAX;
                for(int k=j;k<=i;k++)
                    val_min=min(val_min,k+max(dp[j][k-1],dp[k+1][i]));
                dp[j][i]=val_min;
            }
        }
        return dp[1][n];
    }
};