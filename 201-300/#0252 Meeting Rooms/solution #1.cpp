class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& lhs, vector<int>& rhs) {
            if (lhs[0] == rhs[0]) {
                return lhs[1] < rhs[1];
            } else {
                return lhs[0] < rhs[0];
            }
        });
        
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < intervals[i - 1][1]) {
                return false;
            }
        }
        
        return true;
    }
};
