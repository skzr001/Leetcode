class Solution {
//method 1: sliding windows
//O(n) running time
public:
    //Method 1: Sliding window
    int minSubArrayLen(int s, vector<int>& nums) {
        int first=0,last=0;
        int sum=0;
        int min_len=INT_MAX;
        while(last<nums.size()){
            sum+=nums[last];
            while(sum>=s){
                min_len=min(min_len,last-first+1);
                sum-=nums[first];
                first++;
            }
            last++;
        }
        return min_len==INT_MAX?0:min_len;
    }
};