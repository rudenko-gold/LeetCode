class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        for (int i = 0; i < order.size(); ++i) {
            pos[order[i]] = i;
        }
        
        for (int i = 1; i < words.size(); i++) {
            const string& word1 = words[i - 1];
            const string& word2 = words[i];
            if (isLess(word2, word1)) {
                return false;
            }
        }
        
        return true;
    }
    
    bool isLess(const string& s1, const string& s2) {
        for (int i = 0; i < min(s1.size(), s2.size()); i++) {
            if (pos[s1[i]] > pos[s2[i]]) {
                return false;
            } else if (pos[s1[i]] < pos[s2[i]]) {
                return true;
            }
        }    
        
        return s1.size() < s2.size();
    }
    
    unordered_map<char, int> pos;
};
