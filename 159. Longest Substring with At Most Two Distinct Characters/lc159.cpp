/*
Method 1:Sliding window.
*/
/*
ece
e:2
c:1

eceb
m.size()>2
--m[e]=1
left=1
--m[c]==0 m.erase(c)

*/
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int res=0,left=0;
        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++){
            ++m[s[i]];
            while(m.size()>2){
                if(--m[s[left]]==0) m.erase(s[left]);
                ++left;
            }
            res=max(res,i-left+1);
        }
        return res;
    }
};


