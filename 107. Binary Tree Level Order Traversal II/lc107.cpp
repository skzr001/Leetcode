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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(root==NULL) return res;

        res.push_back(vector<int>{root->val});
        q.push(root);

        while(!q.empty()){
            vector<int> cur_val;
            for(int i=0,n=q.size();i<n;i++){
                TreeNode* cur=q.front();
                q.pop();
                if(cur->left) {
                    cur_val.push_back(cur->left->val);
                    q.push(cur->left);
                }
                if(cur->right){
                    cur_val.push_back(cur->right->val);
                    q.push(cur->right);
                }
            }
            if(!cur_val.empty()) res.push_back(cur_val);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
/*
            3
        9       20
            15      17

res:3
q:3

cur
*/