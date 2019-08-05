class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> perm(s.size() + 1);
        int lo = 0, hi = s.size();
        
        for (size_t i = 0; i < s.size(); i++) {
            if (s[i] == 'I') {
                perm[i] = lo++;
            } else {
                perm[i] = hi--;
            }
        }
        
        perm.back() = lo;
        
        return perm;
    }
};
