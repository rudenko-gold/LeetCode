class Solution {
public:
    int checkRecord(int n) {
        const long long mod = 1000000000 + 7;
        vector<long long> dp(n + 2);
        dp[0] = 1;
        dp[1] = 2;
        dp[2] = 4;
        
        for (int i = 3; i < n + 1; i++) {
            dp[i] = ((dp[i - 1] + dp[i - 2]) % mod + dp[i - 3]) % mod;
        }
        long long ans = dp[n];
        
        for (int i = 0; i < n; i++) {
            ans += (dp[i] * dp[n - i - 1]) % mod; 
            ans %= mod;
        }
        return ans;
    }
};
