class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxi = prices[n-1];
        int profit = 0;
        for(int i=n-2;i>=0;i--){
            int cost = maxi-prices[i];
            profit = max(profit, cost);
            maxi = max(maxi, prices[i]);
        }
        return profit;
    }
};