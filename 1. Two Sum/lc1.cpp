/*
Time complexity is O(n).
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> res;
        for(int i=0;i<nums.size();++i)
            m[nums[i]]=i;
        for(int i=0;i<nums.size();++i){
            int diff=target-nums[i];
            if(m.count(diff)&&m[diff]!=i){//check whether diff exist and whether we use the same element.
                res.push_back(i);
                res.push_back(m[diff]);
                return res;
            }
        }
        return res;
    }
};



/*
A more compact version
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();++i){
            if(m.count(target-nums[i])){
                return {i,m[target-nums[i]]};
            }
            m[nums[i]]=i;
        }
        return {};
    }
};


