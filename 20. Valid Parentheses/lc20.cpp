class Solution {
public:
bool isValid(string s) {
    stack<char> stk;
    for (char &c : s) {
        switch (c) {
            case '(': case '[': case '{':
                stk.push(c); break;
            case ')':
                if (stk.empty() || stk.top() != '(') return false;
                stk.pop(); break;
            case ']':
                if (stk.empty() || stk.top() != '[') return false;
                stk.pop(); break;
            case '}':
                if (stk.empty() || stk.top() != '{') return false;
                stk.pop(); break;
            default:
                throw invalid_argument("input string contains invalid characters");
        }
    }
    return stk.empty();
}
};