class Solution {
public:
    bool isMatch(string s, string p) {//like edit problem
        if(p.empty()) return s.empty();
        if(s.empty()) return p[1]=='*'&&isMatch(s,p.substr(2));
        if(p[1]=='*')
            return isMatch(s,p.substr(2))||(s[0]==p[0]||p[0]=='.')&&isMatch(s.substr(1),p);
        else 
            return (s[0]==p[0]||p[0]=='.')&&isMatch(s.substr(1),p.substr(1));
    }
};