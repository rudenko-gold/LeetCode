class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size(), 0);
        
        if (s.back() != '0') {
            dp[s.size() - 1] = 1;
        }
        
        for (int i = s.size() - 2; i >= 0; --i) {
            int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if (s[i] != '0') {
                dp[i] += dp[i + 1];
            } 
            if (num < 27 && num > 9) {
                if (i + 2 >= s.size()) {
                    dp[i]++;
                } else {
                    dp[i] += dp[i + 2];
                }
            }
        }
        
        return dp[0];
    }
};
