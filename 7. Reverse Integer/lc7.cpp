/*
It is specified that the intergers is within the 32-bits signed.
So we don't have to consider big numbers.
The solution is rather straightforward. We extract the last digits of given interger, and multiply it 10 one time and add next digit.
For example.
Input:123.
num=3
num=num*10+2=32
num=num*10+1=321
if num exceed 32 digit, return 0
else return num

Corner case
1. Input overflow.
2. Negative integer.
*/
/*
有一个地方我没有考虑到,要用long long来存最终结果.因为int类型最大是2^32-1. 翻转之后的数字很有可能大于这个范围.
最后做类型判断的时候要考虑正负的最大整形
*/
class Solution {
public:
    int reverse(int x) {
        long long num=0;
        while(x){
            int digit=x%10;
            x/=10;
            num=num*10+digit;
        }
        return (num>INT_MAX||num<INT_MIN)?0:num;
    }
};