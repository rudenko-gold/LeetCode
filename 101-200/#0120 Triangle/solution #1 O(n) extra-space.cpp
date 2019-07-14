class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0) {
            return 0;
        }
        
        vector<int> dp = triangle[0];
        vector<int> next_dp;
        for (int i = 1; i < triangle.size(); i++) {
            next_dp = triangle[i];
            next_dp[0] += dp[0];
            next_dp[next_dp.size() - 1] += dp[dp.size() - 1];
            for (int j = 1; j < next_dp.size() - 1; j++) {
                next_dp[j] += min(dp[j], dp[j - 1]);
            }
            dp = next_dp;
        }
        
        int ans = dp[0];
        for (int i = 1; i < dp.size(); i++) {
            ans = min(ans, dp[i]);
        }
        return ans;
    }
};
