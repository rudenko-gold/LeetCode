class Solution {
public:
    struct Number {
        int first = -1;
        int last = -1;
        int cnt = 0;
    };
    
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, Number> m;
        int nums_degree = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (m[nums[i]].first == -1) {
                m[nums[i]].first = i;
            }
            m[nums[i]].last = i;
            m[nums[i]].cnt++;
            if (m[nums[i]].cnt > nums_degree) {
                nums_degree = m[nums[i]].cnt;
            }
        }
        int ans = numeric_limits<int>::max();
        for (auto& number : m) {
            if (number.second.cnt == nums_degree) {
                ans = min(ans, number.second.last - number.second.first + 1);
            }
        }
        return ans;
    }
};
