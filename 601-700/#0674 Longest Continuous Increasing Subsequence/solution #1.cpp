class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        
        int ans = 0;
        int cnt = 1;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                ans = max(ans, cnt);
                cnt = 1;
            } else {
                cnt++;
            }
        }
        ans = max(cnt, ans);
        return ans;
    }
};
