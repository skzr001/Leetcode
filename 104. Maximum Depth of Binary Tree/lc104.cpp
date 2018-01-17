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
    int maxDepth(TreeNode* root) {
        return root?max(maxDepth(root->left),maxDepth(root->right))+1:0;
    }
};

/*
Iterative DFS.
*/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        stack<TreeNode*> stk;
        stack<int> depth;
        int res=0;
        stk.push(root);
        depth.push(1);
        while(!stk.empty()){
            TreeNode* cur=stk.top();
            stk.pop();
            int num=depth.top();
            depth.pop();
            if(cur->left==NULL&&cur->right==NULL){
                res=max(res,num);
            }
            else{
                if(cur->left){
                    stk.push(cur->left);
                    depth.push(num+1);
                }
                if(cur->right){
                    stk.push(cur->right);
                    depth.push(num+1);
                }
            }
        }
        return res;
    }
};

//BFS method
/*
Iterative bfs.
*/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        queue<TreeNode*> q;
        int depth=0;
        q.push(root);
        while(!q.empty()){
            ++depth;
            for(int i=0,n=q.size();i<n;++i){//dealing one layer.
                TreeNode* cur=q.front();
                q.pop();
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }
        return depth;
    }
};