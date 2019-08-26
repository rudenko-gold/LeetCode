class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 1;
        int started = num;
        if (num <= 1) {
            return false;
        }
        for (int factor = 2; factor <= sqrt(num); factor++) {
            if (num % factor == 0) {
                sum += factor;
                if (factor * factor != num) {
                    sum += num / factor;
                }
            }
        }
        
        cout << sum;
        return sum == started;
    }
};
