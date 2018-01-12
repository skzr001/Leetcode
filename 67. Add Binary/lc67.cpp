/*

*/
class Solution {
public:
    string addBinary(string a, string b) {
        int na=a.size(),nb=b.size();
        int n=max(na,nb)+1;
        string res(n,'0');
        for(int i=n-1,i1=na-1,i2=nb-1,carry=0;i>=0;--i,--i1,--i2){
            int va=(i1>=0)?a[i1]-'0':0;
            int vb=(i2>=0)?b[i2]-'0':0;
            int sum=va+vb+carry;
            res[i]=sum%2+'0';
            carry=sum/2;
        }
        auto pos=res.find_first_not_of('0');
        return pos==string::npos?"0":res.substr(pos);
    }
};