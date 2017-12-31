class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        /*
        First group could have less than k characters. When the first group is seperated by the first dash.
        If there are dash and that dash is exactly between two groups, then we leave the dash.
        We have to adjust the first group. For example: ABCDE k=3. We have AB-CDE.
        So I have to implement the iteration backward.
        */
        string res;
        int i=S.size()-1;
        int cnt=K;
        while(i>=0){
            if(S[i]!='-'){
                res.push_back(S[i]);
                cnt--;
            }
            if(cnt==0){
                cnt=K;
                res.push_back('-');
            }
            i--;
        }
        if(res.back()=='-')
            res.pop_back();
        reverse(res.begin(),res.end());
        std::transform(res.begin(), res.end(), res.begin(), ::toupper);
        return res;
    }
};

/*
The code above is rather straightforward.
For the input array, we should adjust the first group to accommodate the remaining group.
For the remaining group, we do not need to consider the dash. We just push K element and then push a dash.
If we do this process backward, the remaining element must belong to the first group.
There is a corner case. If the first element contains exactly K elements. We still push a dash even it is unnecessary.
Then we have to remove it and reverse the string and return it.
*/
