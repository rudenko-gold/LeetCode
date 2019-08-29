class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> freq;
        
        for (auto c : s) {
            freq[c]++;
        }
        
        int odd_cnt = 0;
        
        for (auto& [c, cnt] : freq) {
            if (cnt % 2 == 1) {
                odd_cnt++;
            }
        }
        
        return odd_cnt <= 1;
    }
};
