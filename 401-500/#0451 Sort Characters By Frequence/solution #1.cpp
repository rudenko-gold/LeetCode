class Solution {
public:
    string frequencySort(string s) {    
        unordered_map<char, int> freq;
        for (int i = 0; i < s.size(); ++i) {
            freq[s[i]]++;
        }
        sort(s.begin(), s.end(), [&freq](char lhs, char rhs) {
            if (freq[lhs] != freq[rhs]) {
                return freq[lhs] > freq[rhs];
            } else {
                return lhs < rhs;
            }
        });
        
        return s;
    }
};
