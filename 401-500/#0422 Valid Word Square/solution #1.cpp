class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        if (words.empty()) {
            return 0;
        }
        
        for (int j = 0; j < words[0].size(); j++) {
            string s = "";
            for (int i = 0; i < words.size(); i++) {
                if (words[i].size() > j) {
                    s += words[i][j];
                }
            }
            if (s != words[j]) {
                return false;
            }
        }
        
        return true;
    }
};
