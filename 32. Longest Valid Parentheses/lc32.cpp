class Solution {
public:
    int longestValidParentheses(string s) {//using stack to perform DP
        stack<int> stk;
        stk.push(-1);
        int len=0;
        for(int i=0;i<s.size();i++){
            int t=stk.top();
            if(s[i]!=-1&&s[i]==')'&&s[t]=='('){
                stk.pop();
                len=max(len,i-stk.top());
            }
            else stk.push(i);
        }
        return len;
    }
};