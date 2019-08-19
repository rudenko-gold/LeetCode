class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& a, vector<vector<int>>& queries) {
        int curr_sum = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] % 2 == 0) {
                curr_sum += a[i];
            }
        }
        vector<int> ans;
        ans.reserve(queries.size());
        
        for (auto& query : queries) {
            int ind = query[1];
            int val = query[0];
        
            if (val % 2 == 0) {
                if (a[ind] % 2 == 0) {
                    a[ind] += val;
                    curr_sum += val;
                } else {
                    a[ind] += val;
                }
            } else {
                if (a[ind] % 2 == 0) {
                    curr_sum -= a[ind];
                    a[ind] += val;
                } else {
                    a[ind] += val;
                    curr_sum += a[ind];
                }
            }
            
            ans.push_back(curr_sum);
        }
        
        return ans;
    }
};
