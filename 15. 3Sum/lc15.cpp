/*
O(n^2) time complexity and O(n^2) space complexity.
The most important part is how to eliminate duplicate element.
Through control the pointers.
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums,int target=0) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();++i){
            if(nums[i]>0) break;
            if(i>0&&nums[i]==nums[i-1]) continue;
            int diff=target-nums[i];
            int left=i+1,right=nums.size()-1;
            while(left<right){
                if(nums[left]+nums[right]>diff) --right;
                else if(nums[left]+nums[right]<diff) ++left;
                else{
                    res.push_back({nums[i],nums[left],nums[right]});
                    while(left+1<=right&&nums[left]==nums[left+1]) ++left;
                    while(right-1>=left&&nums[right]==nums[right-1]) --right;
                    ++left,--right;
                }
            }
        }
        return res;
    }
};

/*
using set to help eliminate duplicate element.
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums,int target=0) {
        set<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();++i){
            if(nums[i]>0) break;
            //if(i>0&&nums[i]==nums[i-1]) continue;
            int diff=target-nums[i];
            int left=i+1,right=nums.size()-1;
            while(left<right){
                if(nums[left]+nums[right]>diff) --right;
                else if(nums[left]+nums[right]<diff) ++left;
                else{
                    res.insert({nums[i],nums[left],nums[right]});
                    while(left+1<=right&&nums[left]==nums[left+1]) ++left;
                    while(right-1>=left&&nums[right]==nums[right-1]) --right;
                    ++left,--right;
                }
            }
        }
        return vector<vector<int>>(res.begin(),res.end());
    }
};
