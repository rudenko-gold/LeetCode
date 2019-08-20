class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        unordered_map<int, set<char>> m;
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                m[i - j].insert(matrix[i][j]);
                if (m[i - j].size() > 1) {
                    return false;
                }
            }
        }
        
        return true;
    }
};
