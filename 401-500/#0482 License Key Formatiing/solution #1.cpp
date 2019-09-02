class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string ans = "";
        int dash_cnt = 0;
        for (int i = S.size() - 1; i >= 0; i--) {
            if (S[i] != '-') {
                ans.push_back(toupper(S[i]));
                if ((ans.size() - dash_cnt) % K == 0) {
                    ans.push_back('-');
                    dash_cnt++;
                }
            }
        }
        if (ans.back() == '-') {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
