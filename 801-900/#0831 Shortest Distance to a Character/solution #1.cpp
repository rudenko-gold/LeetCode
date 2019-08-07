class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> fromRight(S.size());
        vector<int> fromLeft(S.size());
        vector<int> ans(S.size());
        
        for (size_t i = 0; i < S.size(); ++i) {
            if (S[i] == C) {
                fromLeft[i] = 0;
            } else {
                if (i) {
                    fromLeft[i] = fromLeft[i - 1] + 1;
                } else {
                    fromLeft[i] = S.size() + 1;
                }
            }
        }
        
        for (int i = S.size() - 1; ; --i) {
            if (S[i] == C) {
                fromRight[i] = 0;
            } else {
                if (i == S.size() - 1) {
                    fromRight[i] = S.size() + 1;
                } else {
                    fromRight[i] = fromRight[i + 1] + 1;
                }
            }
            
            if (i == 0) {
                break;
            }
        }
        
        for (size_t i = 0; i < S.size(); ++i) {
            ans[i] = min(fromLeft[i], fromRight[i]);
        }
        
        return ans;
    }
};
