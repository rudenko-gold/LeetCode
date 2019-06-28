class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto begin = lower_bound(nums.begin(), nums.end(), target);
        auto end = upper_bound(nums.begin(), nums.end(), target);
        if (begin == nums.end()) {
            return {-1, -1};
        }
        
        if (*begin != target) {
            return {-1, -1};
        } else {
            return {begin - nums.begin(), end - nums.begin() - 1};
        }
    }
};
