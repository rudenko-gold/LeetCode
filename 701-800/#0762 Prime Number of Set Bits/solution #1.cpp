class Solution {
public:
    bool isPrime(int n) {
        if (n == 1) {
            return false;
        } else if (n == 2) {
            return true;
        } else if (n % 2 == 0) {
            return false;
        }
        
        for (int i = 3; i <= sqrt(n); i += 2) {
            if (n % i == 0) {
                return false;
            }
        }
        
        return true;
    }
    
    int bitsCount(int n) {
        int ans = 0;
        while (n > 0) {
            ans += n % 2;
            n /= 2;
        }
        return ans;
    }
    
    int countPrimeSetBits(int L, int R) {
        int ans = 0;
        
        for (int n = L; n <= R; ++n) {
            if (isPrime(bitsCount(n))) {
                ans++;
            }
        }
        
        return ans;
    }
};
