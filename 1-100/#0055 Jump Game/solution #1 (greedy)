class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxPos = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (i <= maxPos && i + nums[i] > maxPos) {
                maxPos = i + nums[i];
            }
        }
        return maxPos >= n - 1;
    }
};
