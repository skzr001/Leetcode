class Solution {
public:
    string longestPalindrome(string s) {//brute force method
        //possible follow up? also a valid answer?
        int max_length=0;
        int first=0;
        int l,r;

        for(int mid=1;mid<2*s.size();mid++){
            for(l=(mid-1)/2,r=mid/2;l>=0&&r<s.size()&&s[l]==s[r];l--,r++);
            if(r-l-1>max_length){
                max_length=r-l-1;
                first=l+1;
            }
        }
        return s.substr(first,max_length);
    }
};

//naive method with running
class Solution {
public:
    string longestPalindrome(string s) {//navie method withg prunning optimization
        int max_length=0;
        int first=0;
        int l,r,mid_l,mid_r;
        for(mid_l=0;mid_l<s.size();mid_l=mid_r){
            for(mid_r=mid_l;mid_r<s.size()&&s[mid_l]==s[mid_r];mid_r++);
            for(l=mid_l-1,r=mid_r;l>=0&&r<s.size()&&s[l]==s[r];l--,r++);
            if(r-l-1>max_length){max_length=r-l-1;first=l+1;}
        }
        return s.substr(first,max_length);
    }
};}