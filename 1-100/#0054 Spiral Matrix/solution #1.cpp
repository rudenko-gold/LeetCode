class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int i = 0; 
        int j = 0;
        int netraulElement = numeric_limits<int>::min();
        int vect = 0;
        vector<int> ans;
        int n = matrix.size();
        if (n == 0) {
            return {};
        }
        int m = matrix[0].size();
        while (ans.size() < m * n) {
            ans.push_back(matrix[i][j]);
            matrix[i][j] = netraulElement;
            switch(vect) {
                case 0:
                    if (j + 1 == m || matrix[i][j + 1] == netraulElement) {
                        vect++;
                        i++;
                    } else {
                        j++;
                    }
                    break;
                case 1:
                    if (i + 1 == n || matrix[i + 1][j] == netraulElement) {
                        vect++;
                        j--;
                    } else {
                        i++;
                    }
                    break;
                case 2:
                    if (j == 0 || matrix[i][j - 1] == netraulElement) {
                        vect++;
                        i--;
                    } else {
                        j--;
                    }
                    break;
                case 3:
                    if (i == 0 || matrix[i - 1][j] == netraulElement) {
                        vect++;
                        j++;
                    } else {
                        i--;
                    }
                    break;
            }
            vect %= 4;
        }
        return ans;
    }
};
