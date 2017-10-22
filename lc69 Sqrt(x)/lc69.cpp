class Solution {
public:
    //binary search
    //x is an interger.When x is a float number, the solution will be totally different.
    int mySqrt(int x) {
        int l=1,r=x,ret;
        while(l<=r){
            int mid=(l+r)/2;
            if(mid<=x/mid){l=mid+1,ret=mid;}
            else r=mid-1;
        }
        return ret;
    }
};