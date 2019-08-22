class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        ans.reserve(nums.size());

        for (int i = 0; i < nums.size(); ++i) {
            int m = abs(nums[i]) - 1;
            if (nums[m] < 0) {
                ans.push_back(m + 1);
            } else {
                nums[m] *= -1;
            }
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                ans.push_back(i + 1);
            }
        }
        ans.shrink_to_fit();
        return ans;
    }
};
