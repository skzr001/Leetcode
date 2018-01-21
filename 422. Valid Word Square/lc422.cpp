/*
Straightforward solution.
Just compare the kth row and col.
Pay attention to the corner case. In case of access no existing memory.
*/
class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        if(words.empty()) return true;
        if(words[0].empty()) return false;
        for(int i=0;i<words.size();++i){
            for(int j=0;j<words[i].size();++j){
                if(j>=words.size()||i>=words[j].size()||words[i][j]!=words[j][i])
                    return false;
            }
        }
        return true;
    }
};