class Solution {
public:
    int countSubstrings(string s) {
        int cnt = 0;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; i - j >= 0 && i + j < s.size(); ++j) {
                if (s[i - j] != s[i + j]) {
                    break;
                } else {
                    cnt++;
                }
            }
            
            if (i && s[i] == s[i - 1]) {
                for (int j = 0; i - 1 - j >= 0 && i + j < s.size(); j++) {
                    if (s[i - 1 - j] != s[i + j]) {
                        break;
                    } else {
                        cnt++;
                    }
                }
            }
        }
        
        return cnt;
    }
};
