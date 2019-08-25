class Solution {
public:
    bool wordPattern(string pattern, string str) {
        stringstream ss(str);
        vector<string> s;
        while (!ss.eof()) {
            string word;
            ss >> word;
            s.push_back(word);
        }
        if (s.size() != pattern.size()) {
            return false;
        }
        unordered_map<char, set<string>> m;
        
        for (int i = 0; i < pattern.size(); i++) {
            m[pattern[i]].insert(s[i]);
        }
        
        for (auto& p : m) {
            if (p.second.size() > 1) {
                return false;
            }
        }
        
        unordered_map<string, set<char>> h;
        
        for (int i = 0; i < s.size(); i++) {
            h[s[i]].insert(pattern[i]);
        }
        
        for (auto& p : h) {
            if (p.second.size() > 1) {
                return false;
            }
        }
        
        return true;
    }
};
