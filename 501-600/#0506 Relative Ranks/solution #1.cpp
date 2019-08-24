class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> ans(nums.size());
        vector<int> sorted = nums;
        sort(sorted.rbegin(), sorted.rend());
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[sorted[i]] = i;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (m[nums[i]] == 0) {
                ans[i] = "Gold Medal";
            } else if (m[nums[i]] == 1) {
                ans[i] = "Silver Medal";
            } else if (m[nums[i]] == 2) {
                ans[i] = "Bronze Medal";
            } else {
                ans[i] = to_string(m[nums[i]] + 1);
            }
        }
        
        return ans;
        return ans;
    }
};
