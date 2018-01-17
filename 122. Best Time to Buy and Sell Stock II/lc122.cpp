/*
Pay attention to its comparision to the similar quesiton that only made one transaction.
Could be solved in DP procedure. However, the question solved by greedy algorithm is much more efficient.
*/
/*
Solution with some tricks.
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum=0;
        for(size_t i=1;i<prices.size();i++){
            sum+=max(prices[i]-prices[i-1],0);
        }
        return sum;
    }
};

/*
Naive and brute force solution.
For buy pointer, we find the local minimum price to buy.
For sell pointer, we find the local maximum price to sell.
Once we find these two pointer, we reset buy=sell+1, which means we proceed another interval.
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=0,sell=0,sum=0;
        while(buy<prices.size()&&sell<prices.size()){
            while(buy+1<prices.size()&&prices[buy+1]<prices[buy]) buy++;
            sell=buy;
            while(sell+1<prices.size()&&prices[sell+1]>prices[sell]) sell++;
            sum+=prices[sell]-prices[buy];
            buy=sell+1;
        }
        return sum;
    }
};