/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
The most naive solution. Iterative solution.
*/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> stackP;
        stack<TreeNode*> stackQ;
        if(p) stackP.push(p);
        if(q) stackQ.push(q);
        while(!stackP.empty()&&!stackQ.empty()){
            TreeNode* curP=stackP.top();
            TreeNode* curQ=stackQ.top();
            stackP.pop();
            stackQ.pop();

            if(curP->val!=curQ->val) return false;

            if(curP->left) stackP.push(curP->left);
            if(curQ->left) stackQ.push(curQ->left);
            if(stackP.size()!=stackQ.size()) return false;//if NULL exist, return false for left kid.

            if(curP->right) stackP.push(curP->right);
            if(curQ->right) stackQ.push(curQ->right);
            if(stackP.size()!=stackQ.size()) return false;//if NULL exist, return false for right kid.

        }
        return stackP.size()==stackQ.size();
    }
};


/*
The recursive solution.
*/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p||!q) return p==q;
        return p->val==q->val&&isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }
};