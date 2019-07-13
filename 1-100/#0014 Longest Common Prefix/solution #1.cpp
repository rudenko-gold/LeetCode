class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        } else {
            string pref = strs[0];
            for (int i = 1; i < strs.size(); i++) {
                for (int j = 0; j < pref.size(); j++) {
                    if (pref[j] != strs[i][j]) {
                        pref.erase(pref.begin() + j, pref.end());
                        break;
                    }
                }
            }
            return pref;
        }
    }
};
