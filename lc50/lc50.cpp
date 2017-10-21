class Solution {
public:
    //n<0
    //efficient, bit operation
    //我日，突然脑子短路了，想不出怎么做了
    double myPow(double x, int n) {
        if(n==0) return 1;
        double tmp=myPow(x,n/2);
        return n&0x1?n>0?x*tmp*tmp:tmp*tmp/x:tmp*tmp;
        //when n<0, n&0x1 != n%2==1
    }
};