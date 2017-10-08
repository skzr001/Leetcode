class Solution {//最初想了一个非常弱智的暴力解法，真是日了狗了
//this is PREFIX sub array. Not a regular sub array. So we only check from tail to i, whether strs[j][i]==strs[0][i].
// if the equation is true, that's to say all string in strs has a substring (0,i) that all the same.
public:
    string longestCommonPrefix(vector<string>& strs) {//LCS proble
        if(strs.size()==0) return "";//corner case. strs have no element.

        for(int i=0;i<strs[0].size();i++){
            for(int j=1;j<strs.size();j++){
                if(i==strs[j].size()||strs[j][i]!=strs[0][i])
                    return strs[0].substr(0,i);
            }
        }
        return strs[0];
    }
};