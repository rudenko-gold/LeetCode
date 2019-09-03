class Solution {
public:
    int smallestFactorization(int a) {
        if (a == 1) {
            return 1;
        }
        
        vector<int> factors;
        for (int i = 9; i > 1; i--) {
            while (a % i == 0) {
                a /= i;
                factors.push_back(i);
            }
        }
        
        if (a != 1) {
            return 0;
        }
        
        string num_str = "";
        
        for (int i = factors.size() - 1; i >= 0; i--) {
            num_str += to_string(factors[i]);
        }
        cout << numeric_limits<int>::max();
        if (num_str.size() > 10) {
            return 0;
        } else if (num_str.size() == 10 && num_str > to_string(numeric_limits<int>::max())) {
            return 0;
        } else {
            return atoi(num_str.c_str());
        }
    }
};
