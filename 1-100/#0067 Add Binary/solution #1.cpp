class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int n = max(a.size(), b.size()) + 1;
        while (a.size() < n) {
            a += '0';
        }
        while (b.size() < n) {
            b += '0';
        }
        vector<int> num(n, 0);
        
        for (int i = 0; i < n - 1; i++) {
            num[i] += a[i] - '0' + b[i] - '0';
            num[i + 1] += num[i] / 2;
            num[i] %= 2;
        }
        
        if (num.back() == 0) {
            num.pop_back();
        }
        string ans = "";
        for (int i = num.size() - 1; i >= 0; i--) {
            ans += num[i] + '0';
        }
        return ans;
    }
};
