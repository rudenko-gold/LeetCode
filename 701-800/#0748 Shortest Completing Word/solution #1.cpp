class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char, int> license;
        
        for (auto c : licensePlate) {
            if (c >= 'a' && c <= 'z') {
                license[c]++;
            } else if (c >= 'A' && c <= 'Z') {
                license[tolower(c)]++;
            }
        }
        int ans_size = numeric_limits<int>::max();
        string ans = "";
        
        for (auto& word : words) {
            unordered_map<char, int> freq;
            for (auto c : word) {
                if (c >= 'a' && c <= 'z') {
                    freq[c]++;
                } else if (c >= 'A' && c <= 'Z') {
                    freq[tolower(c)]++;
                }
            }
            
            bool check = true;
            
            for (auto& [c, cnt] : license) {
                if (freq[c] < cnt) {
                    check = false;
                    break;
                }
            }
            
            if (check && word.size() < ans_size) {
                ans_size = word.size();
                ans = word;
            }
        }
        
        return ans;
    }
};
