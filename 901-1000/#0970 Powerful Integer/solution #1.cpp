class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> ans;
        
        for (int pow_x = 1; pow_x < bound; pow_x *= x) {
            for (int pow_y = 1; pow_y + pow_x <= bound; pow_y *= y) {
                ans.push_back(pow_x + pow_y);
                if (y == 1) {
                    break;
                } 
            }
            if (x == 1) {
                break;
            }
        }
        
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};
