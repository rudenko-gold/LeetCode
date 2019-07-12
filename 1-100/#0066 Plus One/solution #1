class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans(digits.size() + 1, 0);
        for (int i = 0; i < digits.size(); i++) {
            if (i == 0) {
                ans[i] += 1;
            }
            ans[i] += digits[digits.size() - 1 - i];
            ans[i + 1] += ans[i] / 10;
            ans[i] = ans[i] % 10;
        }
        if (ans.back() == 0) {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
