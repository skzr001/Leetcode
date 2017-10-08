class Solution {//bfs method
    //mimic the behavior of BFS search tree.
    //every iteration we append a layer with 1 digit added.
    //not a real search tree
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.size()==0) return result;
        result.push_back("");//for the first iteration.
        string alphabet[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        for(int i=0;i<digits.size();i++){
            string candidate=alphabet[digits[i]-'0'];
            vector<string> tmp;
            for(int j=0;j<result.size();j++){
                for(int k=0;k<candidate.size();k++){
                    tmp.push_back(result[j]+candidate[k]);
                }
            }
            result.swap(tmp);
        }
        return result;
    }
};