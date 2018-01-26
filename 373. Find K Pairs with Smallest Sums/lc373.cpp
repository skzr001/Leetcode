/*
Corner case: all possible pairs are less than k.
This problem has similar solution like
*/
/*
brute froce method
*/
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> res;
        for(int i=0;i<min((int)nums1.size(),k);++i)
            for(int j=0;j<min((int)nums2.size(),k);++j)
                res.push_back(make_pair(nums1[i],nums2[j]));

        sort(res.begin(),res.end(),
             [](pair<int,int> &a,pair<int,int> &b){return a.first+a.second<b.first+b.second;});

        if(res.size()>k) res.erase(res.begin()+k,res.end());
        return res;
    }
};


/*
Corner case: all possible pairs are less than k.
This problem has similar solution like
*/
/*
priority queue method.
*/
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> res;
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
        for(int i=0;i<min((int)nums1.size(),k);++i){
            for(int j=0;j<min((int)nums2.size(),k);++j){
                if(pq.size()<k) pq.push(make_pair(nums1[i],nums2[j]));
                else if(nums1[i]+nums2[j]<pq.top().first+pq.top().second) {
                    pq.push(make_pair(nums1[i],nums2[j]));
                    pq.pop();
                }
            }
        }
        while(!pq.empty()) {res.push_back(pq.top());pq.pop();}
        return res;
    }
    struct cmp{
        bool operator()(pair<int,int> &a, pair<int,int> &b){
            return a.first+a.second<b.first+b.second;
        }
    };
};