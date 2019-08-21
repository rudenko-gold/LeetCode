class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        int start = 0;
        vector<vector<int>> ans;
        for (int i = 1; i < S.size(); i++) {
            if (S[i] != S[i - 1]) {
                if (i - start > 2) {
                    ans.push_back({start, i - 1});
                } 
                start = i;
            }
        }
        if (S.size() - start > 2) {
            ans.push_back({start, S.size() - 1});
        }
        return ans;
    }
};
