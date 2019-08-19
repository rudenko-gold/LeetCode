class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size()) {
            return false;
        }
        int n = A.size();
        vector<int> m(28, 0);
        bool check = false;
        int not_equal_cnt = 0;
        int pos_l = -1;
        int pos_r = -1;
        
        for (int i = 0; i < n; i++) {
            m[A[i] - 'a']++;
            
            if (m[A[i] - 'a'] > 1) {
                check = true;
            }
            
            if (A[i] != B[i]) {
                not_equal_cnt++;
                if (not_equal_cnt > 2) {
                    return false;
                }
                if (pos_l == -1) {
                    pos_l = i;
                } else {
                    pos_r = i;
                }
            }
        }
        if (not_equal_cnt == 0) {
            return check;
        } else if (not_equal_cnt == 2) {
            return A[pos_l] == B[pos_r] && A[pos_r] == B[pos_l];
        } else {
            return false;
        }
    }
};
