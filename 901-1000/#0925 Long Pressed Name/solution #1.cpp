class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        vector<pair<char, int>> pressed_name = press(name);
        vector<pair<char, int>> pressed_typed = press(typed);
        
        if (pressed_name.size() != pressed_typed.size()) {
            return false;
        } 
        
        for (int i = 0; i < pressed_name.size(); ++i) {
            if (pressed_name[i].first != pressed_typed[i].first) {
                return false;
            } else if (pressed_name[i].second > pressed_typed[i].second) {
                return false;
            }
        }
        
        return true;
    }
    
    vector<pair<char, int>> press(string str) {
        vector<pair<char, int>> ans;
        
        if (str.empty()) {
            return ans;
        }
        
        char c = str[0];
        int cnt = 1;
        
        for (int i = 1; i < str.size(); ++i) {
            if (str[i] == c) {
                cnt++;
            } else {
                ans.push_back(make_pair(c, cnt));
                cnt = 1;
                c = str[i];
            }
        }
        
        ans.push_back(make_pair(c, cnt));
        
        return ans;
    }
};
