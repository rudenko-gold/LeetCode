class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) {
            return 0;
        }
        set<int> se(nums.begin(), nums.end());
        multiset<int> s(nums.begin(), nums.end());
        int ans = 0;
        for (auto el : se) {
            if (k == 0) {
                if (s.count(el + k) > 1) {
                    ans++;
                }  
            } else if (s.find(el + k) != s.end()) {
                ans++;
            }
        }
        
        return ans;
    }
};
