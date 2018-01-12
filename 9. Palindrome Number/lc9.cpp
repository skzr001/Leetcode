/*
121

12
1

1
12

122
12
2

Reverse half of the original variable.

*/
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0||(x!=0&&x%10==0)) return 0;
        int num=0;
        while(num<x){
            num=num*10+x%10;
            x/=10;
        }
        return (num==x||num/10==x)?true:false;
    }
};