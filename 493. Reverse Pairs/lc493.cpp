/*
We use the idea of merge sort.
Suppose we already have two sorted array, then res=left_pair+right_pair+cross_pair
*/
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return merge(nums,0,nums.size()-1);
    }
    int merge(vector<int> &nums, int left, int right){
        if(left>=right) return 0;
        int mid=(left+right)/2;
        int res=merge(nums,left,mid)+merge(nums,mid+1,right);
        for(int i=left,j=mid+1;i<=mid;++i){
            while(j<=right&&nums[i]/2.0>nums[j]) ++j;
            res+=j-(mid+1);
        }
        sort(nums.begin()+left,nums.begin()+right+1);
        return res;
    }
};