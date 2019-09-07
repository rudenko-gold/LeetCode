class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long prod = 1;
        long long ans = numeric_limits<int>::min();
        multiset<long long> pos_prod;
        multiset<long long> neg_prod;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                ans = max(0ll, ans);
                prod = 1;
                pos_prod.clear();
                neg_prod.clear();
                continue;
            }
            
            prod *= 1ll * nums[i];
            if (prod < 0) {
                long long m_prod = prod;
                if (neg_prod.size() > 0) {
                    m_prod /= -(*neg_prod.begin());
                }
                ans = max(ans, m_prod);
                neg_prod.insert(prod * (-1));
            } else {
                ans = max(ans, prod);
                pos_prod.insert(prod);
            }
        }
        return ans;
    }
};
