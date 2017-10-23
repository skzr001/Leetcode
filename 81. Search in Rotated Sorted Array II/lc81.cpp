class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for(int l=0,r=nums.size()-1;l<=r;){
            int m=(l+r)/2;
            if(nums[m]==target||nums[l]==target||nums[r]==target) return true;
            if((nums[m]>target&&target>nums[l])||(nums[m]<nums[l]&&(target<nums[m]||target>nums[l]))) r=m-1;
            else if((nums[m]<target&&target<nums[r])||(nums[m]>nums[r]&&(target>nums[m]||target<nums[r]))) l=m+1;
            else ++l,--r;
        }
        return false;
    }
};