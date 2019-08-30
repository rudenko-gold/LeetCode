class Solution {
public:
    bool isStrobogrammatic(string num) {
        string reversed = num;
        reverse(reversed.begin(), reversed.end());
        for (auto& c : reversed) {
            if (c == '6') {
                c = '9';
            } else if (c == '9') {
                c = '6';
            } else if (c == '2' || c == '3' || c == '5' || c == '4' || c == '7') {
                return false;
            }
        }
        
        return reversed == num;
    }
};
