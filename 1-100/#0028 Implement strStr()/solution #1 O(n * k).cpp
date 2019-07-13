class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        
        for (int i = 0; i + needle.size() - 1 < haystack.size(); ++i) {
            bool check = true;
            for (int j = 0; j < needle.size(); ++j) {
                if (haystack[i + j] != needle[j]) {
                    check = false;
                }
            }
            if (check) {
                return i;
            }
        }
        
        return -1;
    }
};
