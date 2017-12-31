/*
The problem is the same as finding the SCCs of a graph. For simplicity and efficiency, we use a data structure called Union_Find.
This structure is useful  because we have to do many times of update.
When we add a new land, we have to examine its neighbors in order to determine whether they could UNION to a whole land.
That is, when we add a new land, island++.
When its neighbors don't belong to any lands, we do nothing.
When its neighbors belong to some lands, island-num(lands).
*/


class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> res;
        roots=vector<int>(m*n,-1);
        vector<pair<int,int>> dirs={{1,0},{-1,0},{0,1},{0,-1}};
        int island=0;
        for(auto pos:positions){
            int x=pos.first,y=pos.second,idx_p=x*n+y;
            roots[idx_p]=idx_p;
            ++island;
            for(auto dir:dirs){
                int row=x+dir.first,col=y+dir.second,idx_new=n*row+col;
                if(row>=0&&row<m&&col>=0&&col<n&&roots[idx_new]!=-1){
                    int rootNew=find(idx_new),rootPos=find(idx_p);
                    if(rootNew!=rootPos){
                        roots[rootPos]=rootNew;
                        island--;
                    }
                }
            }
            res.push_back(island);
        }
        return res;
    }
private:
    vector<int> roots;
    int find(int idx){
        while(idx!=roots[idx]){
            roots[idx]=roots[roots[idx]];
            idx=roots[idx];
        }
        return idx;
    }
};