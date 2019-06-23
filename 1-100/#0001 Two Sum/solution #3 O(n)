class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> dict;
        for (int i = 0; i < nums.size(); i++) {
            int el = nums[i];
            int remain = target - el;
            if (dict.find(remain) != dict.end()) {
                return {dict[remain], i};
            }
            dict[el] = i;
        }
        return {};
    }
};
