class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int pole[52][52] = { };
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                pole[i + 1][j + 1] = grid[i][j];
            }
        }
        
        int ans = 0;
        for (int i = 1; i <= 50; i++) {
            for (int j = 1; j <= 50; j++) {
                if (pole[i][j] > 0) {
                    ans += 2;
                    ans += max(0, pole[i][j] - pole[i - 1][j]);
                    ans += max(0, pole[i][j] - pole[i + 1][j]);
                    ans += max(0, pole[i][j] - pole[i][j - 1]);
                    ans += max(0, pole[i][j] - pole[i][j + 1]);
                }
            }
        }
        
        return ans;
    }
};
