class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ans = 0;
        int n = board.size();
        
        if (n == 0) {
            return 0;
        }
        
        int m = board[0].size();
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'X') {
                    if (
                        (j - 1 < 0 || board[i][j - 1] == '.') &&
                        (j + 1 == m || board[i][j + 1] == '.') &&
                        (i - 1 < 0 || board[i - 1][j] == '.')
                       ) {
                        // Vertical check
                        ans++;
                    } else if (
                        (i - 1 < 0 || board[i - 1][j] == '.') &&
                        (i + 1 == n || board[i + 1][j] == '.') &&
                        (j - 1 < 0 || board[i][j - 1] == '.')
                    ) {
                        // Horizont check
                        ans++;
                    }
                }
            }
        }
        
        return ans;
    }
};
