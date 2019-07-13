class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        } else if (n == 1) {
            return 10;
        } else {
            if (n > 10) {
                return 0;
            }
            
            int cnt = 9;
            for (int i = 0; i < n - 1; i++) {
                cnt *= (9 - i);
            }
            return cnt + countNumbersWithUniqueDigits(n - 1);
        }
    }
};
