class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = prices[0];
        int maxprofit = 0;

        for(int i=0; i<prices.size(); i++){
            int minsofar = min(minprice, prices[i]);
            minprice = minsofar;
            maxprofit = max(maxprofit, prices[i]-minsofar);
        }
            return maxprofit;
    }
};