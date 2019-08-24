class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int a1, a2, b1, b2;
        stringstream sa(a), sb(b);
        
        sa >> a1;
        sa.ignore(1);
        sa >> b1;
        
        sb >> a2;
        sb.ignore(1);
        sb >> b2;
        
        int A = a1 * a2 - b1 * b2;
        int B = a1 * b2 + a2 *b1;
        
        string ans = to_string(A) + "+" + to_string(B) + "i";
        return ans;
    }
};
