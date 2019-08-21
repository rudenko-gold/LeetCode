class Solution {
public:
    string convertToBase7(int num) {
        string ans = "";
        if (num == 0) {
            return "0";
        } else if (num < 0) {
            ans += "-";
            num *= -1;
        }
        
        vector<char> view;
        view.reserve(12);
        while (num > 0) {
            view.push_back(char(num % 7 + '0'));
            num /= 7;
        }
        
        view.shrink_to_fit();
        for (int i = view.size() - 1; i >= 0; i--) {
            ans += view[i];
        }
            
        return ans;
    }
};
