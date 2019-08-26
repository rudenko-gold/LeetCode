class Solution {
public:
    bool reorderedPowerOf2(int N) {
        unordered_set<string> s;
        
        for (int num = 1; num <= 1000000000; num *= 2) {
            string s_num = to_string(num);
            sort(s_num.begin(), s_num.end());
            s.insert(s_num);
        }
        
        string str_n = to_string(N);
        sort(str_n.begin(), str_n.end());
        
        return s.find(str_n) != s.end();
    }
};
