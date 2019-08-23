class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int min_i = numeric_limits<int>::max();
        int min_j = numeric_limits<int>::max();
        
        for (auto el : ops) {
            min_i = min(min_i, el[0]);
            min_j = min(min_j, el[1]);
        }
        if (min_i == numeric_limits<int>::max() ||
            min_j == numeric_limits<int>::max()) {
            return n * m;
        }
        
        return min_i * min_j;
    }
};
