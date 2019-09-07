class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> sumToPos;
        int sum = 0;
        int ans = 0;
        sumToPos[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sumToPos.find(sum - k) != sumToPos.end()) {
                ans = max(ans, i - sumToPos[sum - k]);
            }
            if (sumToPos.find(sum) == sumToPos.end()) {
                sumToPos[sum] = i;
            }
        }
        
        return ans;
    }
};
