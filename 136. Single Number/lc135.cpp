//As required we must have linear rumtime complexity, we could not use hashtable or any sorting method.
//So we have to use bit operation to save memory space.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(auto num:nums) res^=num;
        return res;
    }
};
