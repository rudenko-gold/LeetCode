class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        unordered_map<int, vector<int>> pos;
        
        for (int i = 0; i < B.size(); ++i) {
            pos[B[i]].push_back(i);
        }
        
        vector<int> ans(A.size());
        for (int i = 0; i < A.size(); ++i) {
            ans[i] = pos[A[i]].back();
            pos[A[i]].pop_back();
        }
        return ans;
    }
};
