class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trust_to(n, 0);
        vector<int> trust_from(n, 0);
        
        for (auto& t : trust) {
            trust_to[t[1] - 1]++;
            trust_from[t[0] - 1]++;
        }
        
        for (int i = 0; i < n; i++) {
            if (trust_to[i] == n - 1 && trust_from[i] == 0) {
                return i + 1;
            } 
        }
        return -1;
    }
};
