class Solution {
public:
    int numDecodings(string s) {
        //the most naive solution is recursion.
        return s.empty()?0:numDecodings(0,s);
    }
    int numDecodings(int p, string &s){
        int n=s.size();
        if(p==n) return 1;
        if(s[p]=='0') return 0;
        int ret=numDecodings(p+1,s);
        if(p<n-1&& (s[p]=='1'||(s[p]=='2'&&s[p+1]<'7'))) ret+=numDecodings(p+2,s);
        return ret;
    }
};

class Solution {
public:
    int numDecodings(string s) {
    //the most naive solution is recursion.
    //we use memorization to elimate time complexity to O(n^2)
        int n=s.size();
        vector<int> mem(n+1,-1);
        mem[n]=1;
        return s.empty()?0:numDecodings(0,s,mem);
    }
    int numDecodings(int i, string &s,vector<int> &mem){
        if(mem[i]>-1) return mem[i];
        if(s[i]=='0') return mem[i]=0;
        int ret=numDecodings(i+1,s,mem);
        if(i<s.size()-1&&(s[i]=='1'||(s[i]=='2'&&s[i+1]<'7'))) ret+=numDecodings(i+2,s,mem);
        return mem[i]=ret;
    }
};

class Solution {
public:
    int numDecodings(string s) {
        //DP solution
        //packet problem
        int n=s.size();
        vector<int> DP(n+1);
        DP[n]=1;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0') DP[i]=0;
            else{
                DP[i]=DP[i+1];
                if(i<n-1&&(s[i]=='1'||(s[i]=='2'&&s[i+1]<'7'))) DP[i]+=DP[i+2];
            }
        }
        return s.empty()?0:DP[0];
    }
};

class Solution {
public:
    int numDecodings(string s) {
        //DP solution
        //packet problem
        //constant space complexity
        int n=s.size();
        int p=1,pp;
        for(int i=n-1;i>=0;i--){
            int cur=s[i]=='0'?0:p;
            if(i<n-1&&(s[i]=='1'||(s[i]=='2'&&s[i+1]<'7'))) cur+=pp;
            pp=p;
            p=cur;
        }
        return s.empty()?0:p;
    }
};