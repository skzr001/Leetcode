class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0||matrix[0].size()==0) return false;
        int row=0;
        int l_row=0,h_row=matrix.size()-1;
        while(l_row<=h_row){
            int m_row=(l_row+h_row)/2;
            if(matrix[m_row][0]==target) return true;
            else if(matrix[m_row][0]<target){row=m_row;l_row=m_row+1;}
            else h_row=m_row-1;
        }
        int l=1,r=matrix[row].size()-1;
        while(l<=r){
            int m=(l+r)/2;
            if(matrix[row][m]==target) return true;
            else if(matrix[row][m]<target) l=m+1;
            else r=m-1;
        }
        return false;
    }
};