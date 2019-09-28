class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        return lengthOfLongestSubstringKDistinct(s, 2);
    }
    
    int lengthOfLongestSubstringKDistinct(string& s, int k) {
        if (k == 0) {
            return 0;
        }
        
        int left_ptr = 0;
        int right_ptr = 0;
        int ans = 0;
        
        int curr_cnt = 0;
        unordered_map<char, int> m;
        
        while (right_ptr < s.size()) {
            if (curr_cnt < k) {
                if (m[s[right_ptr]] == 0) {
                    curr_cnt++;
                }
                
                m[s[right_ptr]]++;
                right_ptr++;
                ans = max(ans, right_ptr - left_ptr);
            } else if (curr_cnt == k) {
                if (m[s[right_ptr]] != 0) {
                    m[s[right_ptr]]++;
                    right_ptr++;
                    ans = max(ans, right_ptr - left_ptr);
                } else {
                    m[s[left_ptr]]--;
                    
                    if (m[s[left_ptr]] == 0) {
                        curr_cnt--;
                    }
                    
                    left_ptr++;
                }
            } else {
                m[s[left_ptr]]--;
                
                if (m[s[left_ptr]] == 0) {
                    curr_cnt--;
                }
                
                left_ptr++;
            }
        }
        
        return ans;
    }
};
