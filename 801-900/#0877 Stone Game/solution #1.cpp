class Solution {
public:
    bool stoneGame(vector<int>& arr) {
        int sum[501][501] = { };
        int dp[501][501] = { };
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            dp[i][i] = arr[i];
        }

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int s = 0;
                for (int k = i; k <= j; k++) {
                    s += arr[k];
                }
                sum[i][j] = s;
            }
        }

        for (int len = 1; len < n; len++) {
            for (int start = 0; start + len < n; start++) {
                int finish = start + len;
                int first_sum = arr[start];
                first_sum += (sum[start + 1][finish] - dp[start + 1][finish]);
                int second_sum = arr[finish];
                second_sum += (sum[start][finish - 1] - dp[start][finish - 1]);
                dp[start][finish] = max(first_sum, second_sum);
            }
        }

        int win = dp[0][n - 1];
        if (sum[0][n - 1] % 2 == 0) {
            if (win == sum[0][n - 1] / 2) {
                return false;
            } else if (win > sum[0][n - 1] / 2) {
                return true;
            } else {
                return false;
            }
        } else {
            if (win > sum[0][n - 1] / 2) {
                return true;
            } else {
                return false;
            }
        }
        return false;
    }
};
