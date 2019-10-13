class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        
        if (n == 0) {
            return {};
        }
        
        vector<int> b(n), c(n);
        
        for (int i = 0; i < n; i++) {
            if (i % k) {
                b[i] = max(nums[i], b[i - 1]);
            } else {
                b[i] = nums[i];
            }
        }
        
        c.back() = nums.back();
        for (int i = n - 2; i >= 0; i--) {
            if ((i + 1) % k) {
                c[i] = max(nums[i], c[i + 1]);
            } else {
                c[i] = nums[i];
            }
        }
        
        vector<int> ans;
        ans.reserve(n - k + 1);
        
        for (int i = 0; i + k <= n; i++) {
            ans.push_back(max(c[i], b[i + k - 1]));
        }
        
        return ans;
    }
};
