/*
Two pointers.
O(nlogn) time complexity. Spent on sorting procedure.
*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int len1=nums1.size(),len2=nums2.size();
        set<int> res;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        for(int i=0,j=0;i<nums1.size()&&j<nums2.size();){
            if(nums1[i]==nums2[j]) {res.insert(nums1[i]);++i;++j;}
            else if(nums1[i]>nums2[j]) ++j;
            else ++i;
        }
        return vector<int>(res.begin(),res.end());
    }
};


/*
Without using set to eliminate duplicates.
Two pointers.
O(nlogn) time complexity. Spent on sorting procedure.
*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int len1=nums1.size(),len2=nums2.size();
        vector<int> res;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        for(int i=0,j=0;i<nums1.size()&&j<nums2.size();){
            if(nums1[i]==nums2[j]&&(res.empty()||res.back()!=nums1[i])) {
                res.push_back(nums1[i]);
                ++i;
                ++j;
            }
            else if(nums1[i]>nums2[j]) ++j;
            else ++i;
        }
        return res;
    }
};