class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        for(int i=1;i<m;i++) grid[i][0]+=grid[i-1][0];
        for(int j=1;j<n;j++) grid[0][j]+=grid[0][j-1];
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
                grid[i][j]=min(grid[i-1][j],grid[i][j-1])+grid[i][j];
        return grid[m-1][n-1];
    }
};

/*
Above is the initial naive solution.
For this question, the transition formula is obvious
grid[i][j]=min(grid[i-1][j],grid[i][j-1])+grid[i][j].

I have meet some likely question. To smoothly formulate the transition, we have to pre-process our DP matrix.
In this question, it is important to initialize the first column and first row.
Then we iteration from (1,1) to (m-1.n-1).
The boundary condition is to avoid i-1 and j-1 exceeding the matrix dimension.
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        //Optimizing space effciency
        //optimized to O(n) space complexity.
        vector<int> cur(n,grid[0][0]);
        for(int i=1;i<n;i++) cur[i]=cur[i-1]+grid[0][i];
        for(int i=1;i<m;i++){
            cur[0]+=grid[i][0];
            for(int j=1;j<n;j++){
                cur[j]=min(cur[j-1],cur[j])+grid[i][j];
            }
        }
        return cur[n-1];
    }
};