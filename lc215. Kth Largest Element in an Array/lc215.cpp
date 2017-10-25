class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {//most naive solution: sort
        sort(nums.begin(),nums.end(),[](int a, int b){return a>b;});
        return nums[k - 1];
    }
};


/*------------------------------------------*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {//divide and conquer
        if(nums.size()==0) return -1;
        int left=0,right=nums.size()-1;
        while(true){
            int pos=partition(nums,left,right);
            if(k-1==pos) return nums[pos];
            if(k-1<pos) right=pos-1;
            else left=pos+1;
        }
    }
private:
    int partition(vector<int> &nums, int left,int right){
        int pivot=nums[left];
        int l=left+1,r=right;
        while(l<=r){
            if(nums[l]<pivot&&nums[r]>pivot) swap(nums[l++],nums[r--]);
            if(nums[l]>=pivot) l++;
            if(nums[r]<=pivot) r--;
        }
        swap(nums[left],nums[r]);
        return r;
    }
};