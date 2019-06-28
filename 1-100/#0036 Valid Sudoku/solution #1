class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool ans = true;
        int n = 9;
        int m = 9;
        for (int i = 0; i < n; i++) {
            set<int> s;
            int cnt = 0;
            for (int j = 0; j < m; j++) {
                if (board[i][j] != '.') {
                    cnt++;
                    s.insert(board[i][j] - '0');
                }
            }
            if (cnt != s.size()) {
                ans = false;
            }
        }
        
        for (int j = 0; j < m; j++) {
            int cnt = 0;
            set<int> s;
            for (int i = 0; i < n; i++) {
                if (board[i][j] != '.') {
                    cnt++;
                    s.insert(board[i][j]);
                }
            }
            if (cnt != s.size()) {
                ans = false;
            }
        }
        
        for (int i = 1; i < 9; i+= 3) {
            for (int j = 1; j < 9; j += 3) {
                set<int> s;
                int cnt = 0;
                if (board[i][j] != '.') {
                    s.insert(board[i][j] - '0');
                    cnt++;
                }
                if (board[i - 1][j] != '.') {
                    s.insert(board[i - 1][j] - '0');
                    cnt++;
                }
                if (board[i + 1][j] != '.') {
                    s.insert(board[i + 1][j] - '0');
                    cnt++;
                }
                if (board[i][j - 1] != '.') {
                    s.insert(board[i][j - 1] - '0');
                    cnt++;
                }
                if (board[i][j + 1] != '.') {
                    s.insert(board[i][j + 1] - '0');
                    cnt++;
                }
                if (board[i - 1][j - 1] != '.') {
                    s.insert(board[i - 1][j - 1] - '0');
                    cnt++;
                }
                if (board[i + 1][j + 1] != '.') {
                    s.insert(board[i + 1][j + 1] - '0');
                    cnt++;
                }
                if (board[i - 1][j + 1] != '.') {
                    s.insert(board[i - 1][j + 1] - '0');
                    cnt++;
                }
                if (board[i + 1][j - 1] != '.') {
                    s.insert(board[i + 1][j - 1] - '0');
                    cnt++;
                }
                if (s.size() != cnt) {
                    ans = false;
                }
            }
        }
        
        return ans;
    }
};
