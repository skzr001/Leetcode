/*
We start from the last slot of num1 in order to to rewrite existing element.
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=m+n-1,i1=m-1,i2=n-1;i>=0;--i){
            int v1=i1>=0?nums1[i1]:INT_MIN;
            int v2=i2>=0?nums2[i2]:INT_MIN;
            if(v1>v2) nums1[i]=nums1[i1--];
            else nums1[i]=nums2[i2--];
        }
    }
};