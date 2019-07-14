class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        
        vector<string> v;
        string str;
        
        while (ss >> str) {
            v.push_back(str);
        }
        
        if (v.size() == 0) {
            return "";
        }
        
        reverse(v.begin(), v.end());
        
        string ans = "";
        for (int i = 0; i < v.size() - 1; ++i) {
            ans += v[i] + " ";
        }
        
        ans += v[v.size() - 1];
        
        return ans;
    }
};
