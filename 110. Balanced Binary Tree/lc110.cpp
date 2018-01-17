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
    bool isBalanced(TreeNode* root) {
        return height(root)!=-1;
    }
private:
    int height(TreeNode* root){
        if(root==NULL) return 0;
        int hl=height(root->left);
        int hr=height(root->right);
        if(abs(hl-hr)>1||hl==-1||hr==-1) return -1;
        return max(hl,hr)+1;
    }
};