class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& m) {
        vector<vector<int>> ans = m;
        
        for (int i = 0; i < m.size(); ++i) {
            for (int j = 0; j < m[i].size(); ++j) {
                int cnt = 0;
                int sum = 0;
                for (int x = max(0, i - 1); x < min((int)m.size(), i + 2); x++) {
                    for (int y = max(0, j - 1); y < min((int)m[x].size(), j + 2); y++) {
                        cnt++;
                        sum += m[x][y];
                    }
                }
                
                ans[i][j] = sum / cnt;
            }
        }
        return ans;
    }
};
