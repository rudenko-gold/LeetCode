class Solution {
public:
    int reverse(long long x) {
        long long ans = 0;
        int sign = x < 0 ? -1 : 1;
        while (x != 0) {      
            if (ans * 10 > (1 << 31) - 1) {
                return 0;
            }
            ans *= 10;
            ans += (x % 10) * sign;
            x /= 10;
        }
        return ans * sign;
    }
};
