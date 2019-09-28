class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        string ans = "";
        int ptr = 0;
        
        for (int k = 0; k < indexes.size(); ++k) {
            for (int i = 1; i < indexes.size(); ++i) {
                if (indexes[i] < indexes[i - 1]) {
                    swap(indexes[i], indexes[i - 1]);
                    swap(sources[i], sources[i - 1]);
                    swap(targets[i], targets[i - 1]);
                }
            }
        }
        
        for (int i = 0; i < S.size(); ++i) {
            if (ptr < indexes.size() && indexes[ptr] == i) {
                string& src = sources[ptr];
                string& trg = targets[ptr];
                
                if (S.substr(i, src.size()) == src) {
                    ans += trg;
                    i += src.size() - 1;
                } else {
                    ans += S[i];
                }
                
                ptr++;
            } else {
                ans += S[i];
            }
        }
        
        return ans;
    }
};
