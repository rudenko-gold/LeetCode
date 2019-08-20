class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        unordered_set<int> b(B.begin(), B.end());
        int alice_sum = 0;
        int bob_sum = 0;
        
        for (auto a : A) {
            alice_sum += a;
        }
        for (auto b : B) {
            bob_sum += b;
        }
        
        int diff = alice_sum - bob_sum;
        
        for (auto candy : A) {
            int needed = candy - (diff / 2);
            if (b.find(needed) != b.end()) {
                return { candy, needed };
            }
        }
        return { -1, -1 };
    }
};
