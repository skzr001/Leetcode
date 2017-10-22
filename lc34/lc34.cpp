class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {//search the lower bound of target and target+1
        if(nums.size()==0) return vector<int>{-1,-1};
        int left=search_lower_bound(nums,target);
        int right=search_lower_bound(nums,target+1)-1;
        if(left<nums.size()&&nums[left]==target)
            return vector<int>{left,right};
        else
            return vector<int>{-1,-1};
    }

    inline int search_lower_bound(vector<int> &nums, int target){
        int l=0,r=nums.size()-1;
        while(l<=r){//pay attention to this IF, through concise confirmation
            int mid=(r-l)/2+l;
            if(nums[mid]<target) l=mid+1;
            else r=mid-1;
        }
        return l;
    }
};
