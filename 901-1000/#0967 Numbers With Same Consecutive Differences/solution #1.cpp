class Solution {
public:
    void dfs(int number, int curr_length, int needed_length, int k) {
        if (curr_length == needed_length) {
            ans.insert(number);
        } else {
            int last_dig = number % 10;
            if (last_dig + k >= 0 && last_dig + k < 10) {
                dfs(number * 10 + last_dig + k, curr_length + 1, needed_length, k);
            }
            if (last_dig - k >= 0 && last_dig - k < 10) {
                dfs(number * 10 + last_dig - k, curr_length + 1, needed_length, k);
            }
        }
    }
    
    vector<int> numsSameConsecDiff(int N, int K) {
        if (N == 1) {
            dfs(0, 1, N, K);
        }
        for (int i = 1; i < 10; i++) {
            dfs(i, 1, N, K);
        }
        return vector<int>(ans.begin(), ans.end());
    }
    
    set<int> ans;
};
