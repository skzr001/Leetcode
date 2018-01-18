class Solution {
public:
    bool checkValidString(string s) {
        return helper(s,0,0);
    }
    bool helper(string s,int start, int cnt){
        if(cnt<0) return false;
        for(int i=start;i<s.size();++i){
            if(s[i]=='('){
                ++cnt;
            }
            else if(s[i]==')'){
                if(cnt<=0) return false;
                --cnt;
            }
            else{//s[i]=='*', three condition.
                return helper(s,i+1,cnt)||helper(s,i+1,cnt+1)||helper(s,i+1,cnt-1);
            }
        }
        return cnt==0;
    }
};

