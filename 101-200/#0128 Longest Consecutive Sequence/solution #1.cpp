class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        
        unordered_set<int> s(nums.begin(), nums.end());
        
        for (auto num : nums) {
            if (s.find(num - 1) == s.end()) {
                int curr_streak = 1;
                while (s.find(num + 1) != s.end()) {
                    curr_streak++;
                    num++;
                }
                ans = max(ans, curr_streak);
            }
        }
        
        return ans;
    }
};
