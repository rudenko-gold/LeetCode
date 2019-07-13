class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        int cnt = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                cnt++;
            } else {
                if (cnt > 0) {
                    ans = cnt;
                }
                cnt = 0;
            }
        }
        if (cnt > 0) {
            ans = cnt;
        }
        return ans;
    }
};
