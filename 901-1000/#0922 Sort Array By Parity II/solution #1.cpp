class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int i = 0;
        int j = 1;
        vector<int> ans(A.size());
        
        for (auto el : A) {
            if (el % 2 == 0) {
                ans[i] = el;
                i += 2;
            } else {
                ans[j] = el;
                j += 2;
            }
        }
        
        return ans;
    }
};
