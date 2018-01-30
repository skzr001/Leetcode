class Solution {
public:
    string reverseStr(string s, int k) {
        int n=s.size();
        int cnt=n/k;
        for(int i=0;i<=cnt;++i){
            if(i%2==0){
                if(i*k+k<n) reverse(s.begin()+i*k,s.begin()+i*k+k);
                else reverse(s.begin()+i*k,s.end());
            }
        }
        return s;
    }
};


class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i=0;i<s.size();i+=2*k){
            reverse(s.begin()+i,min(s.end(),s.begin()+i+k));
        }
        return s;
    }
};