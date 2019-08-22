class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> m;
        for (auto el : deck) {
            m[el]++;
        }
        int g = 0;
        
        for (auto& [num, cnt] : m) {
            g = __gcd(cnt, g);
        }
        
        return g > 1;
    }
};
