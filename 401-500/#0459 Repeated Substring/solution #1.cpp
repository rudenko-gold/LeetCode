class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.size();
        vector<int> factors;
        
        for (int i = 1; i <= sqrt(len); i++) {
            if (len % i == 0) {
                factors.push_back(i);
                factors.push_back(s.size() / i);
            }
        }
        
        for (auto length : factors) {
            if (length == s.size()) {
                continue;
            }
            
            bool check = true;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] != s[(i + length) % s.size()]) {
                    check = false;
                }
            }
            cout << length << endl;
            if (check) {
                return true;
            }
        }
        
        return false;
    }
};
