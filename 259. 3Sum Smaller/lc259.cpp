//I want to whether element in nums is already sorted
/*
The procedure to solve this question is like 3Sum. In order to achieve O(n^2) time complexity, we may use left and right pointer to calculate sum then compared to diff=target-nums[i].
*/
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if(nums.size()<3) return 0;
        int res=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();++i){
            int diff=target-nums[i];
            int left=i+1,right=nums.size()-1;
            while(left<right){
                if(nums[left]+nums[right]<diff){
                    res+=right-left;
                    ++left;
                }
                else --right;
            }
        }
        return res;
    }
};