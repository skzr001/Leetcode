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
    int longestConsecutive(TreeNode* root) {
        if(!root) return 0;
        int res=0;
        dfs(root,root->val,0,res);
        return res;
    }
    void dfs(TreeNode *root, int val, int len,int &res){
        if(!root) return;
        if(root->val==val+1) len++;
        else len=1;
        res=max(res,len);
        dfs(root->left,root->val,len,res);
        dfs(root->right,root->val,len,res);
    }
};

class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        return helper(root,NULL,0);
    }
    int helper(TreeNode *root, TreeNode *p, int res){
        if(!root) return res;
        res=(p&&root->val==p->val+1)?res+1:1;
        return max(res,max(helper(root->left,root,res),helper(root->right,root,res)));
    }
};

//iterative
