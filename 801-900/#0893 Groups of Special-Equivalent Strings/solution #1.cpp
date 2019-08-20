class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        set<string> groups;
        
        for (string& str : A) {
            string odd = "";
            string even = "";
            for (int i = 0; i < str.size(); i++) {
                if (i % 2 == 0) {
                    even += str[i];
                } else {
                    odd += str[i];
                }
            }
            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());
            groups.insert(even + "#" + odd);
        }
        
        return groups.size();
    }
};
