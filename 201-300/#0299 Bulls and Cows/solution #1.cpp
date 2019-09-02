class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        unordered_map<char, int> m;
        for (auto c : secret) {
            m[c]++;
        }
        
        for (int i = 0; i < guess.size(); i++) {
            if (guess[i] == secret[i]) {
                bulls++;
            } 
            if (m[guess[i]] > 0) {
                cows++;
                m[guess[i]]--;
            }
        }
        
        return to_string(bulls) + "A" + to_string(cows - bulls) + "B";
    }
};
