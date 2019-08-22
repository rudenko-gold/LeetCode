class Solution {
public:
    bool validMountainArray(vector<int>& a) {
        if (a.size() < 3) {
            return false;
        }
        
        int max_i = max_element(a.begin(), a.end()) - a.begin();
        
        if (max_i == a.size() - 1 || max_i == 0) {
            return false;
        }
        
        for (int i = 1; i <= max_i; ++i) {
            if (a[i] <= a[i - 1]) {
                return false;
            }
        }
        
        for (int i = max_i; i < a.size() - 1; ++i) {
            if (a[i] <= a[i + 1]) {
                return false;
            }
        }
        
        return true;
    }
};
