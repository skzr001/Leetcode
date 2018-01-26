class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res=0;
        int min_diff=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();++i){
            //if(nums[i]>target) break;
            int diff=target-nums[i];
            int left=i+1,right=nums.size()-1;
            while(left<right){
                int cur=abs(target-nums[i]-nums[left]-nums[right]);
                if(cur<min_diff){
                    min_diff=cur;
                    res=nums[i]+nums[left]+nums[right];
                }
                if(nums[left]+nums[right]>diff) --right;
                else if(nums[left]+nums[right]<diff) ++left;
                else return target;
            }
        }
        return res;
    }
};



