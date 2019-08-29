class Solution {
public:
    int n = 8;
    int m = 8;
        
    double knightProbability(int N, int K, int r, int c) {
        n = N;
        m = N;
        vector<vector<double>> curr_dp(n, vector<double>(n, 0));
        vector<vector<double>> next_dp(m, vector<double>(m, 0));
        curr_dp[r][c] = 1.0;
        
        for (int step = 0; step < K; step++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    vector<vector<int>> moves = {
                        { 2, -1 },
                        { 1, -2 },
                        { -1, -2 },
                        { -2, -1 },
                        { -2, 1 },
                        { -1, 2 },
                        { 1, 2 },
                        { 2, 1 }
                    };
                    
                    for (auto& move : moves) {
                        if (isGoodCell(i + move[0], j + move[1])) {
                            next_dp[i + move[0]][j + move[1]] += curr_dp[i][j] / 8.0;
                        }
                    }
                }
            }
            
            moveTo(next_dp, curr_dp);
            fillZeroes(next_dp);
        }
        
        double ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans += curr_dp[i][j];
            }
        }
        
        return ans;
    }
    
    bool isGoodCell(int i, int j) {
        return (i >= 0 && i < n) && (j >= 0 && j < m);
    }
    
    void moveTo(vector<vector<double>>& src, vector<vector<double>>& dest) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dest[i][j] = src[i][j];
            }
        }
    }
    
    void fillZeroes(vector<vector<double>>& v) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                v[i][j] = 0.0;
            }
        }
    }
};
