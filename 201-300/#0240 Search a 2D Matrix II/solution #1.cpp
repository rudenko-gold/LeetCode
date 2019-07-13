class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) {
            return 0;
        } else if (matrix[0].size() == 0) {
            return 0;
        }
        
        int i = 0;
        int j = matrix[0].size() - 1;
        
        while (true) {
            if (i == matrix.size()) {
                break;
            } else if (j == -1) {
                break;
            }
            
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] > target) {
                j--;
            } else {
                i++;
            }
        }
        
        return false;
    }
};
