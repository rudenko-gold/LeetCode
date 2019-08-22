class Solution {
public:
    bool isPrime(int n) {
        if (n == 2) {
            return true;
        } else if (n == 1) {
            return false;
        } else if (n % 2 == 0) {
            return false;
        }
        
        for (int i = 3; i <= sqrt(n); ++i) {
            if (n % i == 0) {
                return false;
            }
        }
        
        return true;
    }
    
    int reverse(int n) {
        int ans = 0;
        
        while (n > 0) {
            ans *= 10;
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }
    
    int primePalindrome(int n) {
        while (true) {
            if (isPrime(n) && n == reverse(n)) {
                return n;
            } 
            n++;
            if (n > 10000000 && n < 100000000) {
                n = 100000000;
            }
        }
    }
};
