class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int t = 0, a = 0, b = 0;
        
        for(int i = 0; i < nums.size(); ++i) {
            t = (a & ~ b & ~nums[i]) | (~a & b & nums[i]);
            b = (~a & b & ~nums[i]) | (~a & ~b & nums[i]);
            a = t;
        }
        
        return a | b;
    }
};
