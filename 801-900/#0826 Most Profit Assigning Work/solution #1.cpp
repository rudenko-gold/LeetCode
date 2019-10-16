class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> jobs(profit.size());
        for (size_t i = 0; i < profit.size(); ++i) {
            jobs[i] = { difficulty[i], profit[i] };
        }
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());
        int ptr = 0;
        int ans = 0;
        int current_max = 0;
        for (size_t i = 0; i < worker.size(); ++i) {
            while (ptr < jobs.size() && jobs[ptr].first <= worker[i]) {
                current_max = max(current_max, jobs[ptr].second);
                ptr++;
            }
            ans += current_max;
        }
        return ans;
    }
};
