class Solution {
public:
    int numWays(int n, int k) {
        vector<int> dp(max(3, n + 1));
        dp[0] = 0;
        dp[1] = k;
        dp[2] = k * k;
        
        for (int i = 3; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2]) * (k - 1);
        }
        
        return dp[n];
    }
};
