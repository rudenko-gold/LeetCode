class Solution {
public:
    bool backspaceCompare(string S, string T) {
        vector<char> s_view = get_view(S), t_view = get_view(T);
        return s_view == t_view;
    }
    
    vector<char> get_view(const string& str) {
        vector<char> view;
        for (auto& c : str) {
            if (c == '#') {
                if (!view.empty()) {
                    view.pop_back();
                }
            } else {
                view.push_back(c);
            }
        }
        return view;
    }
};
