class Solution {
public:
    int minAddToMakeValid(string s) {
        int bal = 0;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                bal++;    
            } else {
                bal--;
            }
            
            if (bal == -1) {
                ans++;
                bal++;
            }
        }
        
        return bal + ans;
    }
};
