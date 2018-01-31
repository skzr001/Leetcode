/*
We maintain a sorted array. Everytime we insert one element from the end of nums. At that time, the index is the counts[i] we required. Since the array we maintained is a sorted array. Using binary search, the total time complexity is O(nlogn).
*/
/*
What's the difference about duplicates elements?
*/
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> t,res(nums.size());
        for(int i=nums.size()-1;i>=0;--i){
            int left=0,right=t.size();
            while(left<right){
                int mid=(left+right)/2;
                if(t[mid]>=nums[i]) right=mid;
                else left=mid+1;
            }
            t.insert(t.begin()+right,nums[i]);
            res[i]=right;
        }
        return res;
    }
};

/*
We maintain a sorted array. Everytime we insert one element from the end of nums. At that time, the index is the counts[i] we required. Since the array we maintained is a sorted array. Using binary search, the total time complexity is O(nlogn).
*/
/*
What's the difference about duplicates elements?
*/
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> t,res(nums.size());
        for(int i=nums.size()-1;i>=0;--i){
            int d=distance(t.begin(),lower_bound(t.begin(),t.end(),nums[i]));
            res[i]=d;
            t.insert(t.begin()+d,nums[i]);
        }
        return res;
    }
};

/*
Binary search tree.
*/
class Solution {
public:
    struct Node{
        int val,smaller;
        Node *left,*right;
        Node(int v,int s):val(v),smaller(s),left(NULL),right(NULL){}
    };
    int insert(Node* &root,int v){
        if(!root) return (root=new Node(v,0)),0;
        if(root->val>v) return root->smaller++,insert(root->left,v);
        else return insert(root->right,v)+root->smaller+(root->val<v?1:0);
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size());
        Node *root=NULL;
        for(int i=nums.size()-1;i>=0;--i){
            res[i]=insert(root,nums[i]);
        }
        return res;
    }
};