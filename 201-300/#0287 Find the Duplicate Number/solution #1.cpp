class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int m = abs(nums[i]) - 1;
            if (nums[m] < 0) {
                return m + 1;
            } else {
                nums[m] *= -1;
            }
        }
        return 0;
    }
};
