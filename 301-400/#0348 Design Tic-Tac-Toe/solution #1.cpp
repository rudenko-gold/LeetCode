class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) : n(n), diag_state(2, vector<int>(2)), row_state(2), col_state(2) {
        
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    
    // | |x|
    // |x|o|
    int move(int row, int col, int player) {
        row_state[player - 1][row]++;
        col_state[player - 1][col]++;
        
        if (row_state[player - 1][row] == n) {
            return player;
        } 
        
        if (col_state[player - 1][col] == n) {
            return player;
        }
        
        if (col == row) {
            diag_state[player - 1][0]++;
            if (diag_state[player - 1][0] == n) {
                return player;
            }
        }
        
        if (row == n - 1 - col) {
            diag_state[player - 1][1]++;
            if (diag_state[player - 1][1] == n) {
                return player;
            }
        }
        
        return 0;
    }
    
    vector<unordered_map<int, int>> row_state;
    vector<unordered_map<int, int>> col_state;
    vector<vector<int>> diag_state;
    int n;
    
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
