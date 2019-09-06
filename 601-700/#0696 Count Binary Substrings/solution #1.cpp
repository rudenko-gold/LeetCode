class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0;
        vector<int> groups;
        int last = s[0];
        int cnt = 1;
        
        for (int i = 1; i < s.size(); i++) {
            if (last != s[i]) {
                groups.push_back(cnt);
                cnt = 1;
                last = s[i];
            } else {
                cnt++;
            }
        }
        
        groups.push_back(cnt);
        
        for (int i = 0; i + 1 < groups.size(); i++) {
            ans += min(groups[i], groups[i + 1]);
        }
        return ans;
    }
};
