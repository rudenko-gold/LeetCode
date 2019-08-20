class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (r * c != nums.size() * nums[0].size()) {
            return nums;
        }
        
        vector<int> elements;
        elements.reserve(nums.size() * nums[0].size());
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums[i].size(); ++j) {
                elements.push_back(nums[i][j]);
            }
        }
        
        vector<vector<int>> ans(r);
        
        int idx = 0;        
        
        for (int i = 0; i < r; i++) {
            ans[i].reserve(c);
            for (int j = 0; j < c; j++) {
                ans[i].push_back(elements[idx]);
                idx++;
            }
        }
        return ans;
    }
};
