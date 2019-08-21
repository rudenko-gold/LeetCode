class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            int m = abs(nums[i]) - 1;
            if (nums[m] < 0) {
                ans.push_back(m + 1);
            } else {
                nums[m] *= -1;
            }
        }
        return ans;
    }
};
