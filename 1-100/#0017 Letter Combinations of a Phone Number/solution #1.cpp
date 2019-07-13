class Solution {
public:
    vector<string> letterCombinations(string digits) {
        queue<string> q;
        q.push("");
        int n = digits.size();
        for (int t = 0; t < n; t++) {
            int dig = digits[t] - '0';
            int sz = q.size();
            switch (dig) {
                case 0:
                    for (int i = 0; i < sz; i++) {
                        q.push(q.front() + " ");
                        q.pop();
                    }
                    break;
                case 1:
                    break;
                case 2:
                    for (int i = 0; i < sz; i++) {
                        q.push(q.front() + "a");
                        q.push(q.front() + "b");
                        q.push(q.front() + "c");
                        q.pop();
                    }
                    break;
                case 3:
                    for (int i = 0; i < sz; i++) {
                        q.push(q.front() + "d");
                        q.push(q.front() + "e");
                        q.push(q.front() + "f");
                        q.pop();
                    }
                    break;
                case 4:
                    for (int i = 0; i < sz; i++) {
                        q.push(q.front() + "g");
                        q.push(q.front() + "h");
                        q.push(q.front() + "i");
                        q.pop();
                    }
                    break;
                case 5:
                    for (int i = 0; i < sz; i++) {
                        q.push(q.front() + "j");
                        q.push(q.front() + "k");
                        q.push(q.front() + "l");
                        q.pop();
                    }
                    break;
                case 6:
                    for (int i = 0; i < sz; i++) {
                        q.push(q.front() + "m");
                        q.push(q.front() + "n");
                        q.push(q.front() + "o");
                        q.pop();
                    }
                    break;
                case 7:
                    for (int i = 0; i < sz; i++) {
                        q.push(q.front() + "p");
                        q.push(q.front() + "q");
                        q.push(q.front() + "r");
                        q.push(q.front() + "s");
                        q.pop();
                    }
                    break;
                case 8:
                    for (int i = 0; i < sz; i++) {
                        q.push(q.front() + "t");
                        q.push(q.front() + "u");
                        q.push(q.front() + "v");
                        q.pop();
                    }
                    break;
                case 9:
                    for (int i = 0; i < sz; i++) {
                        q.push(q.front() + "w");
                        q.push(q.front() + "x");
                        q.push(q.front() + "y");
                        q.push(q.front() + "z");
                        q.pop();
                    }
                    break;
            }
        }
        vector<string> ans;
        while (q.size() > 0) {
            ans.push_back(q.front());
            q.pop();
        }
        if (ans.size() == 1) {
            return {};
        }
        return ans;
    }
};
