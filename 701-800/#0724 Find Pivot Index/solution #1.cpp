class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> pref(nums.size()), suff(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            pref[i] = nums[i];
            if (i) {
                pref[i] += pref[i - 1];
            }
            
            suff[nums.size() - 1 - i] = nums[nums.size() - 1 - i];
            if (i) {
                suff[nums.size() - 1 - i] += suff[nums.size() - 1 - i + 1];
            }
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                if (suff[i + 1] == 0) {
                    return i;
                }
            } else if (i == nums.size() - 1) {
                if (pref[i - 1] == 0) {
                    return i;
                }
            } else {
                if (pref[i - 1] == suff[i + 1]) {
                    return i;
                }
            }
        }
        
        return -1;
    }
};
