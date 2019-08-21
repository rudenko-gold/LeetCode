class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int idx = 0;
        while (idx < bits.size() - 1) {
            if (bits[idx] == 1) {
                idx += 2;
            } else {
                idx++;
            }
        }
        
        return idx == bits.size() - 1;
    }
};
