class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        bool ans = true;
        int Xcnt = 0;
        int Ocnt = 0;
        vector<set<char>> state(8);        
        for (int i = 0; i < 3; i++) {
            state[0].insert(board[i][i]);
            state[1].insert(board[i][2 - i]);
            state[2].insert(board[0][i]);
            state[3].insert(board[1][i]);
            state[4].insert(board[2][i]);
            state[5].insert(board[i][0]);
            state[6].insert(board[i][1]);
            state[7].insert(board[i][2]);
        }
        
        for (auto& line : board) {
            for (auto& el : line) {
                if (el == 'X') {
                    Xcnt++;
                } else if(el == 'O') {
                    Ocnt++;
                }
            }
        }
        
        int winXCnt = 0;
        int winYCnt = 0;
        for (auto& s : state) {
            if (s.size() == 1 && *s.begin() != ' ') {
                if (*s.begin() == 'X') {
                    winXCnt++;
                } else {
                    winYCnt++;
                }
            } 
        }
        
        if (winXCnt > 0) {
            if (winYCnt > 0) {
                ans = false;
            } else if (winXCnt > 2) {
                ans = false;
            }
        }
        
        if (winYCnt > 0) {
            if (winXCnt > 0) {
                ans = false;
            } else if (winYCnt > 2) {
                ans = false;
            }
        }
        cout << winXCnt << " " << Xcnt << " " << Ocnt;
        if (winXCnt > 0 && Ocnt == Xcnt) {
            ans = false;
        }
        
        if (winYCnt > 0 && Xcnt > Ocnt) {
            ans = false;
        } 
        
        if (Ocnt > Xcnt) {
            ans = false;
        }
        
        if (Xcnt - Ocnt > 1) {
            ans = false;
        }
        
        return ans;
    }
};
