class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i + 2 < grid.size(); i++) {
            for (int j = 0; j + 2 < grid[i].size(); j++) {
                if (isMagicSquare(grid, i, j)) {
                    ans++;
                }
            }
        }
        return ans;
    }
    
    bool isMagicSquare(vector<vector<int>>& grid, int i, int j) {
        set<int> s;
        for (int p = i; p < i + 3; p++) {
            for (int t = j; t < j + 3; t++) {
                s.insert(grid[p][t]);
            }
        }
        
        if (s.size() != 9) {
            return false;
        } else if (*s.begin() != 1 || *(--s.end()) != 9) {
            return false;
        }
        
        vector<int> sums = {
            grid[i][j] + grid[i][j + 1] + grid[i][j + 2],
            grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2],
            grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2],
            
            grid[i][j] + grid[i + 1][j] + grid[i + 2][j],
            grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1],
            grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2],
            
            grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2],
            grid[i + 2][j] + grid[i + 1][j + 1] + grid[i][j + 2],
        };
        
        for (int i = 1; i < sums.size(); ++i) {
            if (sums[i] != sums[i - 1]) {
                return false;
            }
        }
        
        return true;
    }
};
