class Solution {
public:
    int numWays(int n, int k) {
        if(n<=1||!k) return n*k;
        int s=k,d=(k-1)*k;
        for(int i=2;i<n;i++){
            int cur=s+d;
            s=d;
            d=(k-1)*cur;
        }
        return s+d;
    }
};
/*
s:the last 2 bits that have the same color;
d:the last 2 bits that have the different color;
d1: the first of the 2 bits;
d2: the second of the 2bits;
initial conditon is n=2, s=k,d1=k,d2=k*(k-1), in n=2 circumstance, the total ammounts = s+d2.
transition formula:
tmp = s+d2;
s=d2;
d2=(k-1)*(tmp)
if n==1, return k;
if k==0, return 0;
*/
*/
