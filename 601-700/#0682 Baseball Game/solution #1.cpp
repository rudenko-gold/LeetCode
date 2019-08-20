class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> points;
        
        for (auto& op : ops) {
            if (op == "+") {
                int score = 0;
                if (points.size() > 1) {
                    score += points[points.size() - 2];
                }
                if (points.size() > 0) {
                    score += points.back();
                }
                points.push_back(score);
            } else if (op == "D") {
                int score = 0;
                if (points.size() > 0) {
                    score += (points.back() * 2);
                }
                points.push_back(score);
            } else if (op == "C") {
                if (!points.empty()) {
                    points.pop_back();
                }
            } else {
                int score = atoi(op.c_str());
                points.push_back(score);
            }
        }
        int sum = 0;
        for (auto point : points) {
            sum += point;
        }
        return sum;
    }
};
