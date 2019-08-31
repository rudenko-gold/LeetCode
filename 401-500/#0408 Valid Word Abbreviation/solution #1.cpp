class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        string s = "";
        int num = 0;
        for (int i = 0; i < abbr.size(); i++) {
            if (abbr[i] >= 'a' && abbr[i] <= 'z') {
                for (int j = 0; j < num; j++) {
                    s += '?';
                }
                s += abbr[i];
                num = 0;
            } else {
                if (num == 0 && abbr[i] == '0') {
                    return false;
                }
                num *= 10;
                num += (abbr[i] - '0');
                if (num > 10000000) {
                    return false;
                }
            }
        }
        for (int j = 0; j < num; j++) {
            s += '?';
        }
        
        if (s.size() != word.size()) {
            return false;
        } else {
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] != '?' && s[i] != word[i]) {
                    return false;
                }
            }
            return true;
        }
        
    }
};
