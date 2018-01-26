class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();++i){
            for(int j=i+1;j<nums.size();++j){
                int diff=target-nums[i]-nums[j];
                int left=j+1,right=nums.size()-1;
                while(left<right){
                    if(nums[left]+nums[right]<diff) ++left;
                    else if(nums[left]+nums[right]>diff) --right;
                    else {
                        res.insert({nums[i],nums[j],nums[left],nums[right]});
                        ++left,--right;
                    }
                }
            }
        }
        return vector<vector<int>> (res.begin(),res.end());
    }
};



