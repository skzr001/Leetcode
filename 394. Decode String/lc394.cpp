/*
Recursive solution.
Every time we meet a ‘[’, we treat it as a subproblem so call our recursive function to get the content in that ‘[’ and ‘]’. After that , repeat that content for ‘num’ times.
Every time we meet a ‘]’, we know a subproblem finished and just return the ‘word’ we got in this subproblrm.
*/

class Solution {
public:
    string decodeString(string s) {
        int pos = 0;
        return solver(pos, s);
    }
    string solver(int &pos, string s){
        int num=0;
        string word="";
        for(;pos<s.size();pos++){
            char cur=s[pos];
            if(cur=='['){
                string curStr=solver(++pos,s);
                for(;num>0;num--) word+=curStr;
            }
            else if(cur==']') return word;
            else if(cur>='0'&&cur<='9') num=num*10+cur-'0';
            else word+=cur;
        }
        return word;
    }
};

