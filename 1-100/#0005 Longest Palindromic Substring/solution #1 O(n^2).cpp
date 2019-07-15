class Solution {
public:
    string longestPalindrome(string s) {
        int ans = 0;
        int l = 0;
        int r = 0;
        for (int i = 0; i < s.size(); ++i) {
            bool check = true;
            for (int j = 0; i - j >= 0 && i + j < s.size(); ++j) {
                if (s[i - j] != s[i + j]) {
                    break;
                } else {
                    if (2 * j + 1 > ans) {
                        ans = 2 * j + 1;
                        l = i - j;
                        r = i + j;
                    }
                }
            }
            
            if (i && s[i] == s[i - 1]) {
                for (int j = 0; i - 1 - j >= 0 && i + j < s.size(); j++) {
                    if (s[i - 1 - j] != s[i + j]) {
                        break;
                    } else {
                        if ((j + 1) * 2 > ans) {
                            ans = (j + 1) * 2;
                            l = i - 1 - j;
                            r = i + j;
                        }
                    }
                }
            }
        }
        
        return s.substr(l, r - l + 1);
    }
};
