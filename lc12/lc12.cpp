class Solution {//naive solution

f1 //Processing 10^n every iteration.
f0
public:
    string intToRoman(int num) {
        string Roman("MDCLXVI"),result("");
        for(int base=1000,p1=0;num>0;num%=base,base/=10,p1+=2){
            int bit=num/base;
            switch(bit){
                case 9:result+=Roman[p1];result+=Roman[p1-2];break;
                case 4:result+=Roman[p1];result+=Roman[p1-1];break;
                default://like VIII III
                    if(bit>=5){
                        result+=Roman[p1-1];
                        bit-=5;
                    }
                    for(int n=0;n<bit;n++) result+=Roman[p1];
            }
        }
        return result;
    }
};

class Solution {//greedy choice
public:
    string intToRoman(int num) {
        vector<int> vals = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> roman = vector<string>{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string result("");
        for(int i=0;i<vals.size();i++)
            for(;vals[i]<=num;num-=vals[i])
                result+=roman[i];

        return result;
    }
};}