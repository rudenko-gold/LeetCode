class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        
        for (int i = 0; i < strs.size(); i++) {
            string s = "";
            vector<int> dict(27, 0);
            for (int j = 0; j < strs[i].size(); j++) {
                dict[strs[i][j] - 'a']++;
            }
            for (int i = 0; i < 27; i++) {
                s += to_string(dict[i]) + "#";
            }
            m[s].push_back(strs[i]);
        }
        
        vector<vector<string>> ans;
        for (auto el : m) {
            ans.push_back(el.second);
        }
        return ans;
    }
};
