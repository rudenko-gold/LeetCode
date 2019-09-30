class Solution {
public:
    string customSortString(string S, string T) {
        unordered_map<char, int> pos;
        
        for (int i = 0; i < S.size(); ++i) {
            pos[S[i]] = i;
        }
        
        sort(T.begin(), T.end(), [&pos](char lhs, char rhs) {
            return pos[lhs] < pos[rhs]; 
        });
        
        return T;
    }
};
