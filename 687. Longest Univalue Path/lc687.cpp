/*
The most straightforward method to solve this problem is recursion.
For every node, we calculate maximum lengh between its two children. Because what we required is find  a PATH. For current node, we only can choose the larger left or right.
As for the res update, res=max(res,left+right).
*/
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        int res=0;
        helper(root,res);
        return res;
    }
    int helper(TreeNode* node,int& res){
        if(!node) return 0;
        int left=helper(node->left,res);
        int right=helper(node->right,res);
        left=(node->left&&node->val==node->left->val)?left+1:0;
        right=(node->right&&node->val==node->right->val)?right+1:0;
        res=max(res,left+right);
        return max(left,right);
    }
};