class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        
        while (l < r - 3) {
            int m1 = l + (r - l) / 3;
            int m2 = r - (r - l) / 3;
            
            if (nums[m1] < nums[m2]) {
                l = m1;
            } else {
                r = m2;
            }
        }
        
        int ans = l;
        
        if (l + 1 < nums.size() && nums[l + 1] > nums[ans]) {
            ans = l + 1;
        }
        if (l + 2 < nums.size() && nums[l + 2] > nums[ans]) {
            ans = l + 2;
        }
        if (l + 3 < nums.size() && nums[l + 3] > nums[ans]) {
            ans = l + 3;
        }
        
        return ans;
    }
};
