class Solution {
public:
    bool isMatch(string s, string p) {
        int i_star=-1,j_star=-1;
        int i,j;
        for(i=0,j=0;i<s.size();i++,j++){
            if(p[j]=='*'){
                i_star=i;
                j_star=j;
                i--;
            }
            else{
                if(p[j]!=s[i]&&p[j]!='?'){
                    if(i_star>=0){
                        i=i_star;
                        j=j_star;
                        i_star++;
                    }
                    else return false;
                }
            }
        }
        while(p[j]=='*') j++;
        return j==p.size();
    }
};
/*
This is the most naive solution.

Let's pay attention to the * in the string p. "*" can replace any substring or empty.
We let i and j be the pointer for S and P.
If p[j]=='*', we only consider the relationship between S[i to the end] and P[j+1 to the end]. If P's substring Psub could match S's one
substring S.sub. And S's such substring mush to the end of the string. Then P and S is match. As * could replace the substring between Psub and Ssub.

Our code minic the process I say above.

The worst case time complexity is O(n^2) and the space complexity is O(n).
*/