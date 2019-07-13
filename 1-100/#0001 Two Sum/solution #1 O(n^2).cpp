class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            int remain = target - nums[i];
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] == remain && j != i) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};
