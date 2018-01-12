/*
Using internal function.
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        size_t pos_last=s.find_last_not_of(' ');
        if(pos_last==string::npos) return 0;
        size_t pos_first=s.find_last_of(' ',pos_last);
        return (pos_first==string::npos)?pos_last+1:pos_last-pos_first;
    }
};


/*
Using pointers.
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=0,tail=s.length()-1;
        while(tail>=0&&s[tail]==' ') tail--;
        while(tail>=0&&s[tail--]!=' ') len++;
        return len;
    }
};