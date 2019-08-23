class Solution {
public:
    int arrangeCoins(int n) {
        int step = 1;
        
        while (true) {
            if (n < step) {
                return step - 1;
            } else {
                n -= step;
                step++;
            }
        }
        return 0;
    }
};
