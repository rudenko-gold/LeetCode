class Solution {
public:
    int fourSumCount(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d) {
        unordered_map<int, int> hash_table;
        for (int i = 0; i < a.size(); ++i) {
            for (int j = 0; j < b.size(); ++j) {
                hash_table[a[i] + b[j]]++;;
            }
        }
        int ans = 0;
        for (int i = 0; i < c.size(); ++i) {
            for (int j = 0; j < d.size(); ++j) {
               ans += hash_table[-1 * (c[i] + d[j])];
            }
        }
        
        return ans;
    }
};
