class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        if (n == 0) {
            return 0;
        }
        
        vector<int> dp[3];
        dp[0].resize(n);
        dp[1].resize(n);
        dp[2].resize(n);
        
        dp[0][0] = costs[0][0];
        dp[1][0] = costs[0][1];
        dp[2][0] = costs[0][2];
        
        for (int i = 1; i < n; i++) {
            dp[0][i] = min(dp[1][i - 1], dp[2][i - 1]) + costs[i][0];
            dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]) + costs[i][1];
            dp[2][i] = min(dp[1][i - 1], dp[0][i - 1]) + costs[i][2];
        }
        
        return min(dp[0][n - 1], min(dp[1][n - 1], dp[2][n - 1]));
    }
};
