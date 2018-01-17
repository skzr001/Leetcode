/*
Keyword: sorted, without duplicates. Convert intergers array to range arrays.
If num[i]+1=num[i+1], it belongs to the same range, and it can be merged.
Usually this problem is a randomly distributed array, so we have to sort first.
Besides, we have to also consider whether or not a single number denotes a range.
*/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int i=0,n=nums.size();
        int start=0,end=0;
        for(int i=0;i<n;i++){
            if(i+1<n&&nums[i]+1==nums[i+1]){//when i=n-1,num[i+1] access an undefined memory, is it applicable?
                end=i+1;
            }
            else{
                res.push_back(start==end?to_string(nums[start]):
                             to_string(nums[start])+"->"+to_string(nums[end]));
                start=end=i+1;
            }
        }
        return res;
    }
};

//同样的解法,但是写起来更顺畅,参考网上代码

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int i=0;
        while(i<nums.size()){
            int j=1;
            while(i+j<nums.size()&&nums[i+j]-nums[i]==j) ++j;
            res.push_back(j<=1?to_string(nums[i]):
                         to_string(nums[i])+"->"+to_string(nums[i+j-1]));
            i+=j;
        }
        return res;
    }
};