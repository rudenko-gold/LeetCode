class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int ans = 0;
        
        if (A.size() == 0) {
            return 0;
        }
        
        for (int j = 0; j < A[0].size(); ++j) {
            bool is_sorted = true;
            for (int i = 1; i < A.size(); ++i) {
                if (A[i][j] < A[i - 1][j]) {
                    is_sorted = false;
                }
            }
            if (!is_sorted) {
                ans++;
            }
        }
        
        return ans;
    }
};
