/*
The similar procedure like "Single Number 1".
Our problem has two required element, so we have to decide our original array to two parts.
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff=accumulate(nums.begin(),nums.end(),0,bit_xor<int>());
        vector<int> res(2,0);
        diff&=-diff;
        for(int num:nums){
            if(num&diff) res[0]^=num;
            else res[1]^=num;
        }
        return res;
    }
};