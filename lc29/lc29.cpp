/*
We cannot use naive solution by subtracting divisor all the time. It's too slow.
For example, when implementing 2^31-1/1, we have to iterate 2^31 times.
*/
class Solution {
    //I don't know...
    //1. How long does the two integers
    //2.
public:
    int divide(int dividend, int divisor) {//naive solution is too slow. We have to implement this process using bit operation.
         if (!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        int result=0;
        while(dvd>=0){
            dvd-=dvs;
            result++;
        }
        result--;
        return sign == 1 ? result : -result;
    }
};



class Solution {
/*
Let's consider 15/2. In binary form is 1111/10.
First we implement 1111-1000, 1000=2<<2, tmp_result=1<<2=4. 15-8=15-2*4, result=4
Second we implement 111-100, 100=2<<1, tmp_result=1<<2=2, 7-4=3 result=6
Then we implement 11-10 inner while loop we don't enter. result=7
terminate.
15=2*7+1
*/
public:
    int divide(int dividend, int divisor) {
        if(divisor==1) return dividend;
        if(divisor==0||(dividend==INT_MIN&&divisor==-1)) return INT_MAX;

        long long abs_dividend=labs(dividend);
        long long abs_divisor=labs(divisor);

        int pos=((dividend<0)^(divisor<0))?-1:1;
        int result=0;

        while(abs_dividend>=abs_divisor){
            long long tmp=abs_divisor;
            long long tmp_result=1;
            while(abs_dividend>=(tmp<<1)){
                tmp<<=1;
                tmp_result<<=1;
            }
            abs_dividend-=tmp;
            result+=tmp_result;
        }
        return pos>0?result:-result;
    }
};