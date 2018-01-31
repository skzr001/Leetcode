class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int res=0;
        long long sum=0;
        multiset<long long> sums;
        sums.insert(0);//真他妈精髓
        for(int i=0;i<nums.size();++i){
            sum+=nums[i];
            res+=distance(sums.lower_bound(sum-upper),sums.upper_bound(sum-lower));
            sums.insert(sum);
        }
        return res;
    }
};


class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long> sums(nums.size()+1,0);
        for(int i=0;i<nums.size();++i)
            sums[i+1]=sums[i]+nums[i];
        return merge(sums,0,sums.size(),lower,upper);
    }
    int merge(vector<long> &sums,int start, int end, int lower, int upper){
        if(end-start<=1) return 0;
        int mid=(start+end)/2;
        int cnt=merge(sums,start,mid,lower,upper)+merge(sums,mid,end,lower,upper);
        int lower_bound=mid,upper_bound=mid,t=mid;
        vector<int> cache(end-start,0);
        for(int i=start,r=0;i<mid;++i,++r){
            while(lower_bound<end&&sums[lower_bound]-sums[i]<lower) ++lower_bound;
            while(upper_bound<end&&sums[upper_bound]-sums[i]<=upper) ++upper_bound;
            while(t<end&&sums[t]<sums[i]) cache[r++]=sums[t++];
            cache[r]=sums[i];
            cnt+=upper_bound-lower_bound;
        }
        copy(cache.begin(),cache.begin()+t-start,sums.begin()+start);
        return cnt;
    }
};