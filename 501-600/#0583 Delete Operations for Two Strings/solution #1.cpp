class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        vector<vector<int>> lcs(n + 1, vector<int>(m + 1));
        
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (i == 0 || j == 0) {
                    lcs[i][j] = 0;
                } else if (word1[i - 1] == word2[j - 1]) {
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;
                } else {
                    lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
                }
            }
        }
        
        int lcs_len = lcs[n][m];
        
        return word1.size() + word2.size() - 2 * lcs_len;
    }
};
