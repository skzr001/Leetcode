class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size()==0) return 0;
        int l=0,r=nums.size()-1;
        while(l<r){
            int mid=(r-l)/2+l;
            if(nums[mid]<target) l=mid+1;
            else r=mid-1;
        }
        if(nums[l]==target) return l;
        else return nums[l]<target?l+1:l;
    }
};