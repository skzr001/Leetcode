class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int m=grid.size(),n=grid[0].size(),res=0;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]=='1'&&!visited[i][j]) {
                    DFS(grid,visited,i,j);
                    res++;
                }
            }
        }
        return res;
    }
    void DFS(vector<vector<char>> &grid, vector<vector<bool>> &visited,int x, int y){
        if(x<0||x>=grid.size()) return;
        if(y<0||y>=grid[0].size()) return;
        if(grid[x][y]!='1'||visited[x][y]) return;
        visited[x][y]=true;
        DFS(grid,visited,x-1,y);
        DFS(grid,visited,x+1,y);
        DFS(grid,visited,x,y-1);
        DFS(grid,visited,x,y+1);
    }
};