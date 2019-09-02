class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        unordered_set<string> pairs_set;
        for (auto& p : pairs) {
            pairs_set.insert(p[0] + "#" + p[1]);
        }
        
        if (words1.size() != words2.size()) {
            return false;
        }        
        
        for (int i = 0; i < words1.size(); i++) {            
            if (pairs_set.find(words1[i] + "#" + words2[i]) == pairs_set.end() &&
                pairs_set.find(words2[i] + "#" + words1[i]) == pairs_set.end() &&
                words1[i] != words2[i]) {
                return false;
            }
        }
        
        return true;
    }
};
