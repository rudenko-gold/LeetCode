class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int a = 0;
        while(m != n) {
            m >>= 1;
            n >>= 1;
            a++;
        }
        return m << a; 
    }
};
