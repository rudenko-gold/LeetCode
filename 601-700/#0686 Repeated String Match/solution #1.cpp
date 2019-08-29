class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int q = 1;
        string S = A;
        for (; S.size() < B.size(); q++) {
            S += A;
        }
        
        if (S.find(B) != S.npos) {
            return q;
        } else if (S += A; S.find(B) != S.npos) {
            return q + 1;
        } else {
            return -1;
        }
    }
};
