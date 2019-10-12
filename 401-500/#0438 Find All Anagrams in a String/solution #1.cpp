class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> pattern_dict;
        
        for (auto ch : p) {
            pattern_dict[ch]++;
        }
        
        vector<int> ans;
        unordered_map<char, int> window_dict;
        
        for (int i = 0; i < p.size(); i++) {
            window_dict[s[i]]++;
        }
        
        for (int i = p.size(); i < s.size(); i++) {
            // cout << i << " ";
            // print_dict(window_dict);
            if (window_dict == pattern_dict) {
                ans.push_back(i - p.size());
            }
            window_dict[s[i - p.size()]]--;
            if (window_dict[s[i - p.size()]] == 0) {
                window_dict.erase(s[i - p.size()]);
            }
            window_dict[s[i]]++;
        }
        if (window_dict == pattern_dict) {
            ans.push_back(s.size() - p.size());
        }
        
        return ans;
    }
    
    void print_dict(unordered_map<char, int>& dict) {
        cout << "[" << endl;
        for (auto& [key, value] : dict) {
            cout << "{ " << key << ", " << value << " }" << endl;
        }
        cout << "]" << endl;
    }
};
