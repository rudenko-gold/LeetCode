class Solution {
public:
    void generate(int n, int openCnt, int closedCnt, string s) {
        if (openCnt + closedCnt == 2 * n) {
            ans.push_back(s);
            return;
        } else {
            if (openCnt < n) {
                generate(n, openCnt + 1, closedCnt, s + "(");
            }
            if (closedCnt < openCnt) {
                generate(n, openCnt, closedCnt + 1, s + ")");
            }
        }
    }
    
    vector<string> generateParenthesis(int n) {
        generate(n, 0, 0, "");
        return ans;
    }
    
    vector<string> ans;
};
