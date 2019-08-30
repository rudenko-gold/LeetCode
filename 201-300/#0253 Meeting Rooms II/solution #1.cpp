class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {   
        vector<pair<int, bool>> timestamps; // true - start, false - finish
        timestamps.reserve(intervals.size() * 2);
        
        for (auto& interval : intervals) {
            timestamps.push_back({interval[0], true});
            timestamps.push_back({interval[1], false});
        }
        
        sort(timestamps.begin(), timestamps.end(), [](pair<int, bool> lhs, pair<int, bool>& rhs) {
            if (lhs.first != rhs.first) {
                return lhs.first < rhs.first;
            } else {
                return rhs.second > lhs.second;
            }
        });
        
        int maxCnt = 0;
        int currCnt = 0;
        
        for (auto& [time, isStart] : timestamps) {
            if (isStart) {
                currCnt++;
                maxCnt = max(maxCnt, currCnt);
            } else {
                currCnt--;
            }
        }
        
        return maxCnt;
    }
};
