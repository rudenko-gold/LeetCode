class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int l = 0;
        int r = numeric_limits<int>::max();
        
        sort(heaters.begin(), heaters.end());
        
        while (l < r) {
            int radius = l + ((r - l) >> 1);
            
            bool check = true;
            
            for (int i = 0; i < houses.size(); ++i) {
                int j = lower_bound(heaters.begin(), heaters.end(), houses[i]) - heaters.begin();
                bool isHeated = false;
                if (j >= 0 && j < heaters.size() && abs(heaters[j] - houses[i]) <= radius) {
                    isHeated = true;
                }
                if (j > 0 && j <= heaters.size() && abs(heaters[j - 1] - houses[i]) <= radius) {
                    isHeated = true;
                }
                if (!isHeated) {
                    check = false;
                    break;
                }
            }
            
            if (check) {
                r = radius;
            } else {
                l = radius + 1;
            }
        }
        return l;
    }
};
