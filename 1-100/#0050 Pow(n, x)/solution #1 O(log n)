class Solution {
public:
    double myPow(double x, int n) {
        if (x == 1) {
            return x;
        } else if (x == -1) {
            if (n % 2 == 0) {
                return 1.0;
            } else {
                return -1.0;
            }
        } else if (n == 0) {
            return 1.0;
        } else if (n > 0) {
            double ans = x;
            double ost = 1.0;
            while (n > 1) {
                if (n % 2 == 0) {
                    ans = ans * ans;
                    n /= 2;
                } else {
                    ost *= ans;
                    n--;
                }
            }
            return ans * ost;
        } else {
            double ans = x;
            double ost = 1.0;
            while (n < -1) {
                if (n % 2 == 0) {
                    ans = ans * ans;
                    n /= 2;
                } else {
                    ost *= ans;
                    n++;
                }
            }
            ans = 1.0 / (ans * ost);
            return ans;
        }
    }
};
