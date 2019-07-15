class Solution {
public:
    void backtrack(int startPos, const string& s, int& ans) {
        if (startPos >= s.size() - 1) {
            if (startPos == s.size() - 1 && s[startPos] == '0') {
                return;
            } else {
                ans++;   
            }
        } else {
            if (s[startPos] != '0') {
                backtrack(startPos + 1, s, ans);
            }
            if ((s[startPos] - '0') * 10 + (s[startPos + 1] - '0') < 27 && 
               (s[startPos] - '0') * 10 + (s[startPos + 1] - '0') > 9) {
                backtrack(startPos + 2, s, ans);
            }
        }
    }
    
    int numDecodings(string s) {
        int ans = 0;
        backtrack(0, s, ans);
        return ans;
    }
};
