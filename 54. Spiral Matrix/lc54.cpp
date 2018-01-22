class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return {};
        int m=matrix.size(),n=matrix[0].size();
        vector<int> res;
        int up=0,down=m-1,left=0,right=n-1;
        while(true){
            for(int col=left;col<=right;++col) res.push_back(matrix[up][col]);
            if(++up>down) break;
            for(int row=up;row<=down;++row) res.push_back(matrix[row][right]);
            if(--right<left) break;
            for(int col=right;col>=left;--col) res.push_back(matrix[down][col]);
            if(--down<up) break;
            for(int row=down;row>=up;--row) res.push_back(matrix[row][left]);
            if(++left>right) break;
        }
        return res;
    }
};