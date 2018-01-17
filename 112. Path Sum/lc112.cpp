/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL) return false;
        if(root->val==sum&&root->left==NULL&&root->right==NULL) return true;
        return hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val);
    }
};


class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            TreeNode* cur=stk.top();
            stk.pop();
            if(cur->left==NULL&&cur->right==NULL){
                if(cur->val==sum) return true;
            }
            if(cur->left) {stk.push(cur->left);cur->left->val+=cur->val;}
            if(cur->right) {stk.push(cur->right);cur->right->val+=cur->val;}

        }
        return false;
    }
};