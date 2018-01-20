/*
目前只想出一些直白的方法,高级的方法还没有思路.
*/
class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string words="";
        for(auto word:sentence) words+=(word+" ");
        int start=0,len=words.size();
        for(int i=0;i<rows;++i){//using start to count how many word can hold.
            start+=cols;
            if(words[start%len]==' ') ++start;
            else{
                while(start>0&&words[(start-1)%len]!=' ') --start;
            }
        }
        return start/len;
    }
};