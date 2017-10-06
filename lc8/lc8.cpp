class Solution {
public:
    int myAtoi(string str) {
        int k=str.find_first_not_of(" tn");
        bool pos=true;
        if(str[k]=='+'||str[k]=='-') pos=(str[k++]=='+');

        long long val=0;
        for(;k<str.size()&&str[k]>='0'&&str[k]<='9';++k){
            val=val*10+str[k]-'0';
            if(val>INT_MAX) return pos?INT_MAX:INT_MIN;
        }
        return pos?val:-val;
    }
};}