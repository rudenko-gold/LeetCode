class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int first_max_idx = 0;
        int second_max_idx = -1;
        int third_max_idx = -1;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > nums[first_max_idx]) {
                first_max_idx = i;
            }
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != nums[first_max_idx]) {
                if (second_max_idx == -1) {
                    second_max_idx = i;
                } else {
                    if (nums[i] > nums[second_max_idx]) {
                        second_max_idx = i;
                    }
                }
            }
        }
        
        if (second_max_idx == -1) {
            return nums[first_max_idx];
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != nums[first_max_idx] && nums[i] != nums[second_max_idx]) {
                if (third_max_idx == -1) {
                    third_max_idx = i;
                } else {
                    if (nums[i] > nums[third_max_idx]) {
                        third_max_idx = i;
                    }
                }
            }
        }
        
        if (third_max_idx == -1) {
            return nums[first_max_idx];
        } else {
            return nums[third_max_idx];
        }
    }
};
