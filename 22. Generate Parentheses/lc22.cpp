//This problem could be solved using stack or recursion.
//It is a brute force method.
/*
The termination condition is that left must less than right. otherwise some right may appear ahead of left. this is no matching.
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(n,n,"",res);
        return res;
    }
    void helper(int left,int right,string out, vector<string> &res){
        if(left>right) return;
        if(left==0&&right==0) res.push_back(out);
        else{
            if(left>0) helper(left-1,right,out+"(",res);
            if(right>0) helper(left,right-1,out+")",res);
        }
    }
};

