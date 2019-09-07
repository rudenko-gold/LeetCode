class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        
        vector<int> first_half(nums.begin(), nums.begin() + n / 2);
        vector<int> second_half(nums.begin() + n / 2, nums.end());
        
        vector<long long> first_half_sums;
        vector<long long> second_half_sums;
        
        for (int mask = 0; mask < (1 << first_half.size()); mask++) {
            long long sum = 0;
            for (int i = 0; i < first_half.size(); ++i) {
                if ((1 << i) & mask) {
                    sum += first_half[i];
                } else {
                    sum -= first_half[i];
                }
            }
            first_half_sums.push_back(sum);
        }
        
        for (int mask = 0; mask < (1 << second_half.size()); mask++) {
            int sum = 0;
            for (int i = 0; i < second_half.size(); ++i) {
                if ((1 << i) & mask) {
                    sum += second_half[i];
                } else {
                    sum -= second_half[i];
                }
            }
            second_half_sums.push_back(sum);
        }
        
        sort(second_half_sums.begin(), second_half_sums.end());
        
        for (int i = 0; i < first_half_sums.size(); ++i) {
            long long need = 1ll * target - first_half_sums[i];
            ans += upper_bound(second_half_sums.begin(), second_half_sums.end(), need) - 
                   lower_bound(second_half_sums.begin(), second_half_sums.end(), need);
        }
        
        return ans;
    }
};
