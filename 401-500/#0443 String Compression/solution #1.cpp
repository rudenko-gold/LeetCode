class Solution {
public:
    int compress(vector<char>& chars) {
        int last_pos = 0;
        char last = chars[0];
        int cnt = 1;
        
        for (int i = 1; i < chars.size(); i++) {
            if (chars[i] == last) {
                cnt++;
            } else {
                chars[last_pos] = last;
                if (cnt > 1) {
                    string cnt_str = to_string(cnt);
                    for (int j = 0; j < cnt_str.size(); ++j) {
                        chars[last_pos + 1 + j] = cnt_str[j];
                    }
                    last_pos = last_pos + 1 + cnt_str.size();
                } else {
                    last_pos++;
                }
                cnt = 1;
                last = chars[i];
            }
        }
        
        if (cnt > 1) {
            chars[last_pos] = last;
            string cnt_str = to_string(cnt);
            for (int j = 0; j < cnt_str.size(); ++j) {
                chars[last_pos + 1 + j] = cnt_str[j];
            }
            last_pos = last_pos + 1 + cnt_str.size();
        } else {
            chars[last_pos] = last;
            last_pos++;
        }
        
        return last_pos;
    }
};
