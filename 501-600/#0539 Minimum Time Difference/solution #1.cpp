class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int bound = 24 * 60;
        vector<int> time;
        
        for (auto tm : timePoints) {
            stringstream t(tm);
            int h, m;
            t >> h;
            t.ignore(1);
            t >> m;
            time.push_back(h * 60 + m);
        }
        int ans = numeric_limits<int>::max();
        sort(time.begin(), time.end());
        
        for (int i = 1; i < time.size(); i++) {
            ans = min(ans, time[i] - time[i - 1]);
        }
        ans = min(ans, bound - time.back() + time[0]);
        
        return ans;
    }
};
