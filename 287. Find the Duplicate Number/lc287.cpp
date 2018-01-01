/*
O(1) time complexity means we cannot use hash table or other data structure for this assignment.
In this question, the upper bound O(n^2) is rather loose.
I have a naive solution. Simply sort the whole array, then we do a traverse to check whether nums[i] equals nums[j]. If so, just return nums[i].
NONONO, we cannot use sorting method. Because we are required not modifying the array.


*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low=1,high=nums.size()-1;
        int mid;
        while(low<high){
            int count=0;
            mid=(low+high)/2;
            for(auto num:nums)
                if(num<=mid) count++;
            if(count>mid) high=mid;
            else low=mid+1;
        }
        return low;
    }
};