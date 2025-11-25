class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int n = prices.size();
        int maxprofit = 0;

        for(int i=1; i<n; i++){
            buy = min(buy, prices[i]);
            maxprofit = max(maxprofit, prices[i] - buy);
        }
        return maxprofit;
    }
};