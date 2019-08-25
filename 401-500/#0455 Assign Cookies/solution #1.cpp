class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        int ptr = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (ptr >= g.size()) {
                break;
            }
            if (g[ptr] <= s[i]) {
                ptr++;
            }
        }
        return ptr;
    }
};
