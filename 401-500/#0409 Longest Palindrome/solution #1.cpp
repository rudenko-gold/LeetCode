class Solution {
public:
    int longestPalindrome(string s) {
        int sum_even = 0;
        int sum_odd = 0;
        int odd_cnt = 0;
        unordered_map<char, int> freq;
        
        for (auto c : s) {
            freq[c]++;
        }
        
        for (auto& [c, cnt] : freq) {
            if (cnt % 2 == 0) {
                sum_even += cnt;
            } else {
                sum_odd += cnt - 1;
                odd_cnt++;
            }
        }
        if (odd_cnt > 0) {
            return sum_even + sum_odd + 1;
        } else {
            return sum_even;
        }
    }
};
