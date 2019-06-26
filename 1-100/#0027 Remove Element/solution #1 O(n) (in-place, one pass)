class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = nums.size();
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] == val) {
                swap(nums[i], nums[j - 1]);
                j--;
            }
        }
        return j;
    }
};
