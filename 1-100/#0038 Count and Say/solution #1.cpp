class Solution {
public:
    string countAndSay(int n) {
        vector<string> dp(n + 1);
        dp[1] = "1";
        for (int i = 2; i <= n; i++) {
            string s = "";
            string prev = dp[i - 1];
            char last = prev[0];
            int cnt = 1;
            for (int j = 1; j < prev.size(); j++) {
                if (prev[j] != prev[j - 1]) {
                    s += to_string(cnt) + last;
                    cnt = 1;
                    last = prev[j];
                } else {
                    cnt++;
                }
            }
            if (cnt > 0) {
                s += to_string(cnt) + last;
            }
            dp[i] = s;
        }
        return dp[n];
    }
};
