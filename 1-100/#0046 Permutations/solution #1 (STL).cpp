class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> perm(n);
        for (int i = 0; i < n; i++) {
            perm[i] = i;
        }
        vector<vector<int>> ans;
        ans.push_back(nums);
        while (next_permutation(perm.begin(), perm.end())) {
            vector<int> curr_perm(n);
            for (int i = 0; i < n; i++) {
                curr_perm[i] = nums[perm[i]];
            }
            ans.push_back(curr_perm);
        }
        return ans;
    }
};
