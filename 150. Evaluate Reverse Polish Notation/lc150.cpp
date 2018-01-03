class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        string s=tokens.back();
        tokens.pop_back();
        if(s!="+"&&s!="-"&&s!="*"&&s!="/") return stoi(s);
        int b=evalRPN(tokens),a=evalRPN(tokens);
        // Does every operation valid?
        if(s=="+") return a+b;
        if(s=="-") return a-b;
        if(s=="*") return a*b;
        if(s=="/") return a/b;
    }
};