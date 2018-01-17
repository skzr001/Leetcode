//Compare with "Single Number 1". Pay attention how to use bit operation.
/*
Method 1.
We maintain a 32 bits intergers. For every bits, we calculate the sum of 1's on this bit and mod it by 3. When we done, the ramining 1's on the 32 integers is the result we want.
For example.
Input: {3, 3, 1, 3}
res=0;
res=01;
res=01;
return res;
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int i=0;i<32;i++){
            int sum=0;
            for(int j=0;j<nums.size();j++){
                sum+=(nums[j]>>i)&1;
            }
            res|=(sum%3)<<i;
        }
        return res;
    }
};

/*
Method 2.
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a=0,b=0;
        for(auto num:nums){
            b=(b^num)&~a;
            a=(a^num)&~b;
        }
        return b;
    }
};