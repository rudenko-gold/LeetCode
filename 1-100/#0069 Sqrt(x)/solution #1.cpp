class Solution {
public:
    int mySqrt(int x) {
        if (x == 1) {
            return 1;
        }
        int l = 0;
        int r = x;
        while (l + 1 < r) {
            int m = (l + r) >> 1;
            if (m <= x / m) {
                l = m;
            } else {
                r = m;
            }
        }
        return l;
    }
};
