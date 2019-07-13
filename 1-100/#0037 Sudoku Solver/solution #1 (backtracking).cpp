class Solution {
public:
    bool backtrack(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    continue;
                }
                for (char k = '1'; k <= '9'; k++) {
                    board[i][j] = k;
                    if (isValidSudoku(board, i, j) && backtrack(board)) {
                        return true;
                    }
                    board[i][j] = '.';
                }
                if (board[i][j] == '.') {
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }
    
    bool isValidSudoku(const vector<vector<char>>& board, int i, int j) {
        unordered_set<char> row, col, box;
        for (int x = 0; x < 9; ++x ) {
            if (board[i][x] != '.' && !row.insert(board[i][x]).second) {
                return false;
            }
        }
        
        for (int x = 0; x < 9; ++x) {
            if (board[x][j] != '.' && ! col.insert(board[x][j]).second) {
                return false;
            }
        }
        
        for(int r = (i / 3) * 3, end_r = r + 3; r < end_r; ++r) {
            for(int c = (j / 3) * 3, end_c = c + 3; c < end_c; ++c) {
                if(board[r][c] != '.' && ! box.insert(board[r][c]).second) {
                    return false;
                }
            }
        }
        return true;
    }
};
