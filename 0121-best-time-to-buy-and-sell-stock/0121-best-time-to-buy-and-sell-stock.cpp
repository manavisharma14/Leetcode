class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minCost = prices[0];

        for(int i=1; i<prices.size(); i++){
            if(prices[i] < minCost){
                minCost = prices[i];
            }
            else{
            profit = max(profit, prices[i] - minCost);
        }
        }
        return profit;
    }
};