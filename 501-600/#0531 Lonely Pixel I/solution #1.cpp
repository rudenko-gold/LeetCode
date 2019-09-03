class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        if (picture.size() == 0) {
            return 0;
        }
        
        vector<int> row_black_cnt(picture.size(), 0);
        vector<int> col_black_cnt(picture[0].size(), 0);
        
        for (int i = 0; i < picture.size(); ++i) {
            for (int j = 0; j < picture[i].size(); ++j) {
                if (picture[i][j] == 'B') {
                    row_black_cnt[i]++;
                    col_black_cnt[j]++;
                }
            }
        }
        
        int ans = 0;
        for (int i = 0; i < picture.size(); ++i) {
            for (int j = 0; j < picture[i].size(); ++j) {
                if (picture[i][j] == 'B' && row_black_cnt[i] == 1 && col_black_cnt[j] == 1) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};
