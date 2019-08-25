class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, set<char>> m;
        if (s.size() != t.size()) {
            return false;
        }
        
        for (int i = 0; i < s.size(); i++) {
            m[s[i]].insert(t[i]);
        }
        
        for (auto& [c, s] : m) {
            if (s.size() > 1) {
                return false;
            }
        }
        
        m.clear();
        
        for (int i = 0; i < s.size(); i++) {
            m[t[i]].insert(s[i]);
        }
        
        for (auto& [c, s] : m) {
            if (s.size() > 1) {
                return false;
            }
        }
        
        return true;
    }
};
