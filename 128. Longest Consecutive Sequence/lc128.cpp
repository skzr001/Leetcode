/*
In this question, we have to find a linear method returning the length of the longest consecutive element.
So we couldn't use any sorting algorithms.
Hash talbe has constant time searching, se we use this data structure.
First we store all the elements in nums to an unordered_set.
For each nums[i], we continues search its previous and next value until these two element doesn't exist in
our hash table. If exists, we delete it from hahs table. Of course, we have to delete num[i] first.
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> record(nums.begin(),nums.end());
        int res=0;
        for(auto i:nums){
            if(record.find(i)==record.end()) continue;
            record.erase(i);
            int prev=i-1,next=i+1;
            while(record.find(prev)!=record.end()) record.erase(prev--);
            while(record.find(next)!=record.end()) record.erase(next++);
            res=max(res,next-prev-1);
        }
        return res;
    }
};