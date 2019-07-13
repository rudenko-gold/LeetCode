class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int i = 0;
        int j = 0;
        int el = 1;
        int vect = 0;
        while (el <= n * n) {
            ans[i][j] = el;
            el++;
            switch(vect) {
                case 0:
                    if (j == n - 1 || ans[i][j + 1] != 0) {
                        vect++;
                        i++;
                    } else {
                        j++;
                    }
                    break;
                case 1:
                    if (i == n - 1 || ans[i + 1][j] != 0) {
                        vect++;
                        j--;
                    } else {
                        i++;
                    }
                    break;
                case 2:
                    if (j == 0 || ans[i][j - 1] != 0) {
                        vect++;
                        i--;
                    } else {
                        j--;
                    }
                    break;
                case 3:
                    if (i == 0 || ans[i - 1][j] != 0) {
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
