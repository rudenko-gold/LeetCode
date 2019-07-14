class Solution {
public:
    int trailingZeroes(int n) {
        if (n == 0) {
            return 0;
        } else {
            return n / 5 + trailingZeroes(n / 5);
        }
    }
};
