class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        } 
        
        vector<int> s = nums;
        sort(s.begin(), s.end());
        int l = 0;
        int r = nums.size() - 1;
        while (l < nums.size() && nums[l] == s[l]) {
            l++;
        }
        
        while (r >= 0 && nums[r] == s[r]) {
            r--;
        }
        return max(0, r - l + 1);
    }
};
