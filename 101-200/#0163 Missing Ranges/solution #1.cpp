class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        
        long long last_missed = lower;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > last_missed) {
                if (1ll * nums[i] - last_missed == 1) {
                    ans.push_back(to_string(last_missed));
                    last_missed = nums[i] + 1;
                } else {
                    ans.push_back(to_string(last_missed) + "->" + to_string(nums[i] - 1));
                    last_missed = 1ll * nums[i] + 1;
                }
            } else {
                last_missed = 1ll * nums[i] + 1;
            }
        }
        
        if (last_missed < upper) {
            ans.push_back(to_string(last_missed) + "->" + to_string(upper));
        } else if (last_missed == upper) {
            ans.push_back(to_string(upper));
        }
        
        return ans;
    }
};
