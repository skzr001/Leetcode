class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,bool> hash;
        int num=0;
        hash[num]=1;
        while(n!=1){
            while(n!=0){
                num+=(n%10)*(n%10);
                n/=10;
            }
            if(hash[num]==1) return n==1;
            else hash[num]=1;
            n=num;num=0;
        }
        return true;
    }
};
