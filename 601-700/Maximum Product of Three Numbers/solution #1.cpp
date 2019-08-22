class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        partial_sort(nums.begin(), nums.end(), nums.begin() + 3);
        if (nums.size() > 3) {
            partial_sort(nums.begin() + 3, nums.end(), nums.begin() + 3 + nums.size() -3, [](int lhs, int rhs) { return lhs > rhs; });
        }
        int ans = numeric_limits<int>::min();
        int n = nums.size();
        for (int i = 0; i < min(n, 6); i++) {
            for (int j = i + 1; j < min(n, 6); j++) {
                for (int k = j + 1; k < min(n, 6); k++) {
                    ans = max(ans, nums[i] * nums[j] * nums[k]);
                }
            }
        }
        return ans;
    }
};
