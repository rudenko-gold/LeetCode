class Solution {
public:
    int countSegments(string s) {
        int cnt = 0;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (cnt > 0) {
                    ans++;
                }
                cnt = 0;
            } else {
                cnt++;
            }
        }
        
        if (cnt > 0) {
            ans++;
        }
        
        return ans;
    }
};
