class Solution {//DP method
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0) return -1;
        int maxv=nums[0];
        for(int i=0,sum=0;i<nums.size();++i){
            sum=max(nums[i],sum+nums[i]);
            maxv=max(maxv,sum);
        }
        return maxv;
    }
};
/*---------------------------------------------------------------------------------------*/
class Solution {
public:
    int MaxSubArray(vector<int>& nums, int l,int h){
        if(l==h) return nums[l];
        int m=(l+h)/2;
        return max(max(MaxSubArray(nums,l,m),MaxSubArray(nums,m+1,h)),MaxCrossing(nums,l,m,h));
    }
    int MaxCrossing(vector<int>& nums,int l,int m,int h){
        int left_max=INT_MIN, right_max=INT_MIN;
        for(int i=m,sum=0;i>=l;i--){//left side continuous max sub-array.
            sum+=nums[i];
            if(left_max<sum) left_max=sum;
        }
        for(int i=m+1,sum=0;i<=h;i++){//right side
            sum+=nums[i];
            if(right_max<sum) right_max=sum;
        }
        return left_max+right_max;
    }
    int maxSubArray(vector<int>& nums) {//divide and conquer
        if(nums.size()==0) return -1;
        return MaxSubArray(nums,0,nums.size()-1);
    }
};