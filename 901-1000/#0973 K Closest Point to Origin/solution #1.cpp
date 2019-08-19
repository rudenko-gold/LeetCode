class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        partial_sort(points.begin(), points.end(), points.begin() + K, 
                      [](vector<int>& p1, vector<int>& p2) {
                          return p1[0] * p1[0] + p1[1] * p1[1] < p2[0] * p2[0] + p2[1] * p2[1]; 
                      });
        
        points.resize(K);
        return points;
    }
};
