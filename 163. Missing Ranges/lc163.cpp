class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        long long start=(long)lower;
        for(int i=0;i<=nums.size();i++){
            long long end=i<nums.size()&&nums[i]<=upper?(long)nums[i]:(long)upper+1;
            if(start==end) start++;
            else if(end>start){
                res.push_back(end-start<=1?to_string(start):
                             to_string(start)+"->"+to_string(end-1));
                start=end+1;
            }
        }
        return res;
    }
};