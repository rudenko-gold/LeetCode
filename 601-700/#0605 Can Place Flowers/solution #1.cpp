class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0;
        int ans = 0;
        vector<int> placed = flowerbed;
        
        for (int i = 0; i < flowerbed.size(); ++i) {
            if (flowerbed[i] == 1) {
                if (i - 1 >= 0) {
                    placed[i - 1] = 1;
                }
                if (i + 1 < placed.size()) {
                    placed[i + 1] = 1;    
                }
            }
        }
        
        for (int i = 0; i < placed.size(); ++i) {
            if (placed[i] == 0) {
                cnt++;
            } else {
                if (cnt % 2 == 1) {
                    ans += (cnt + 1) / 2;
                } else {
                    ans += cnt / 2;
                }
                cnt = 0;
            }
        }
        
        if (cnt % 2 == 1) {
            ans += (cnt + 1) / 2;
        } else {
            ans += cnt / 2;
        }
        return ans >= n;
    }
};
