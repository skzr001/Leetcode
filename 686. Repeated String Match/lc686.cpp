class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        string t=A;
        for(int i=1;i<=B.size()/A.size()+2;++i){
            if(t.find(B)!=string::npos) return i;
            t+=A;
        }
        return -1;
    }
};

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int m=A.size(),n=B.size();
        for(int i=0;i<m;++i){
            int j=0;
            while(j<n&&A[(i+j)%m]==B[j]) ++j;
            if(j==n) return (i+j-1)/m+1;
        }
        return -1;
    }
};