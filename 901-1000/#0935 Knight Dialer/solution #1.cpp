class Solution {
public:
    int knightDialer(int n) {
        const int mod = 1000000000 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(10));

        for (int i = 0; i < 10; ++i) {
            dp[1][i] = 1;
        }

        for (int step = 2; step <= n; step++) {
            dp[step][0] = (dp[step - 1][4] + dp[step - 1][6]) % mod;
            dp[step][1] = (dp[step - 1][8] + dp[step - 1][6]) % mod;
            dp[step][2] = (dp[step - 1][7] + dp[step - 1][9]) % mod;
            dp[step][3] = (dp[step - 1][4] + dp[step - 1][8]) % mod;
            dp[step][4] = ((dp[step - 1][3] + dp[step - 1][9]) % mod + dp[step - 1][0]) % mod;
            dp[step][6] = ((dp[step - 1][7] + dp[step - 1][1]) % mod + dp[step - 1][0]) % mod;
            dp[step][7] = (dp[step - 1][2] + dp[step - 1][6]) % mod;
            dp[step][8] = (dp[step - 1][1] + dp[step - 1][3]) % mod;
            dp[step][9] = (dp[step - 1][4] + dp[step - 1][2]) % mod;
        }

        int ans = 0;

        for (int i = 0; i < 10; ++i) {
            ans += dp[n][i];
            ans %= mod;
        }

        return ans;
    }
};
