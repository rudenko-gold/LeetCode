class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int last1 = numeric_limits<int>::min();
        int last2 = last1;
        int ans = numeric_limits<int>::max();
        
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) {
                last1 = i;
                if (last2 >= 0) {
                    ans = min(ans, abs(last1 - last2));
                }
            } else if (words[i] == word2) {
                last2 = i;
                if (last1 >= 0) {
                    ans = min(ans, abs(last1 - last2));
                }
            }
        }
        
        return ans;
    }
};
