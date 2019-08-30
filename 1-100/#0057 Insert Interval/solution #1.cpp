class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        bool check = true;
        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i][0] >= newInterval[0]) {
                intervals.insert(intervals.begin() + i, newInterval);
                check = false;
                break;
            }
        }
        
        if (check) {
            intervals.push_back(newInterval);
        }
        ans.reserve(intervals.size());
        for (auto& interval : intervals) {
            if (ans.empty()) {
                ans.push_back(interval);
            } else {
                if (interval[0] <= ans.back()[1]) {
                    ans.back()[1] = max(ans.back()[1], interval[1]);
                } else {
                    ans.push_back(interval);
                }
            }
        }
        
        ans.shrink_to_fit();
        
        return ans;
    }
};
