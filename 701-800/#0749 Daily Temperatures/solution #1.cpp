class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> m(101, numeric_limits<int>::max());
        vector<int> ans(T.size(), 0);
        
        for (int i = T.size() - 1; i >= 0; i--) {
            int curr_temp = T[i];
            int day = numeric_limits<int>::max();
            for (int j = curr_temp + 1; j < 101; j++) {
                if (m[j] != numeric_limits<int>::max()) {
                    day = min(day, m[j] - i);
                }
            }
            if (day == numeric_limits<int>::max()) {
                ans[i] = 0;
            } else {
                ans[i] = day;
            }
            m[curr_temp] = i;
        }
        
        return ans;
    }
};
