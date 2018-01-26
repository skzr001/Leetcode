class Solution {
public:
    struct compare{
        bool operator()(const pair<int,pair<int,int>> &a,const pair<int,pair<int,int>> &b){
            return a.first>b.first;
        }
    };
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if(matrix.empty()) return -1;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,compare> pq;
        int m=matrix.size(),n=matrix[0].size();
        for(int i=0;i<n;++i) pq.push(make_pair(matrix[i][0],make_pair(i,0)));

        int res;
        while(k--){
            int t=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            res=t;
            if(j!=m-1) pq.push(make_pair(matrix[i][j+1],make_pair(i,j+1)));
        }
        return res;
    }
};