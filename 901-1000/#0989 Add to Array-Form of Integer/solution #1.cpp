class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        reverse(A.begin(), A.end());
        vector<int> kArr;
        while (K > 0) {
            kArr.push_back(K % 10);
            K /= 10;
        }
        
        vector<int> ans(max(A.size(), kArr.size()) + 1, 0);
        for (int i = 0; i < max(A.size(), kArr.size()); i++) {
            if (i < A.size()) {
                ans[i] += A[i];
            }
            if (i < kArr.size()) {
                ans[i] += kArr[i];
            }
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
        }
        
        if (ans.back() == 0) {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
