class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }
        vector<int> minPrices(prices.size());
        minPrices[0] = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            minPrices[i] = min(minPrices[i - 1], prices[i]);
        }
        int ans = 0;
        for (int i = 1; i < prices.size(); i++) {
            ans = max(ans, prices[i] - minPrices[i - 1]);
        }
        return ans;
    }
};
