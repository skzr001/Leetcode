class Solution {
public:
    string reverseString(string s) {
        int left=0,right=s.size()-1;
        while(left<right){
            char c=s[left];
            s[left++]=s[right];
            s[right--]=c;
        }
        return s;
    }
};


