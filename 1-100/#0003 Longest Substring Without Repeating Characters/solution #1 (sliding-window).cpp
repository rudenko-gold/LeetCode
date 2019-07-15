class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> dict;
        int n = s.size();
        int ans = 0;
        int l = 0;
        int r = 0;
        while (l < n && r < n) {
            if (dict[s[r]] == 0) {
                dict[s[r]] = 1;
                ans = max(ans, r - l + 1);
                r++;
            } else {
                dict[s[l]]--;
                l++;
            }
        }
        return ans;
    }
};
