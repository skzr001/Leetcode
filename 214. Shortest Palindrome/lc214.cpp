lass Solution {//205
public:
    string shortestPalindrome(string s) {
        string s2=s;
        reverse(s2.begin(),s2.end());
        int n=s.size();
        int len;
        for(len=n;len>=0;len--){
            if(s.substr(0,len)==s2.substr(n-len))
                break;
        }
        return s2.substr(0,n-len)+s;
    }
};
/*
s=cpp
s1=ppc
required output:ppcpp
len=3

*/