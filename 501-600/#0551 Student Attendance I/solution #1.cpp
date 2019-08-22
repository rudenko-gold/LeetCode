class Solution {
public:
    bool checkRecord(string s) {
        int A_cnt = 0;
        int L_cnt = 0;
        
        for (auto c : s) {
            if (c == 'A') {
                A_cnt++;
                if (A_cnt > 1) {
                    return false;
                }
                L_cnt = 0;
            } else if (c == 'L') {
                L_cnt++;
                if (L_cnt > 2) {
                    return false;
                }
            } else {
                L_cnt = 0;
            }
        }
        
        return true;
    }
};
