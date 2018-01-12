/*
Implement finding substring function.
Compare each n elements with the elements in haystack.
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        int h=haystack.size(),n=needle.size();
        if(n==0) return 0;
        for(int first=0;first<=h-n;first++){
            bool matched=true;
            for(int i=0,j=first;i<n;i++,j++){
                if(needle[i]!=haystack[j]){
                    matched=false;
                    break;
                }
            }
            if(matched) return first;
        }
        return -1;
    }
};