/*
This problem has a DP structure.
Let dp[i][j] to be the total number of required subsequence between s[0,1...j-1] and T[0,1....i-1].
To initialize, let dp[0][j]=1. Because if T is empty, we only have one choice to delete all the element of S.
let dp[i][0]=0. Because if S is empty, we cannot do any matching.
For the transition formula, we have:
DP[i][j]=DP[i][j-1], if s[i-1]!=t[j-1]. Becuase the matching will definitely contain s[i-1]. So we use the previous solution.
DP[i][j]=DP[i][j-1]+DP[s-1][j-1]. We have two choice, either contain s[j-1] or not.
*/
class Solution {
public:
    int numDistinct(string s, string t) {
        if(s.empty()||t.empty()) return 0;
        int m=t.size(),n=s.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int j=0;j<=n;j++) dp[0][j]=1;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=(t[i-1]==s[j-1])?(dp[i][j-1]+dp[i-1][j-1]):dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};




int m=t.length(), n=s.length()
vector<int> cur(m+1,0);
cur[0]=1;
for(int j=1;j<=n;j++){}
    int pre=1;
    for(int i=1;i<=m;i++){
        int tmp=cur[i];
        cur[i]=cur[i]+(t[i-1]==s[j-1]?pre:0);
        pre=temp;
    }
    return cur[m];
    }
}
