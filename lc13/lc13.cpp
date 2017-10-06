class Solution {
public:
    int romanToInt(string s) {
        int alphabet[256];
        alphabet['I']=1;alphabet['V']=5;
        alphabet['X']=10;alphabet['L']=50;
        alphabet['C']=100;alphabet['D']=500;
        alphabet['M']=1000;

        int val=0;
        for(int i=0,last=2000;i<s.size();i++){
            int current=alphabet[s[i]];
            val+=(current<=last)?current:current-2*last;
            last=current;
        }
        return val;
    }
};}