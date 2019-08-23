class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        vector<pair<int, int>> component;
        vector<vector<int>> used(n, vector<int>(m));
        queue<pair<int, int>> q;
        q.push({sr, sc});
        
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            used[r][c] = 1;
            component.push_back({r, c});
            
            if (r + 1 < n && image[r + 1][c] == image[r][c] && !used[r + 1][c]) {
                q.push({r + 1, c});
            }
            
            if (c + 1 < m && image[r][c + 1] == image[r][c] && !used[r][c + 1]) {
                q.push({r, c + 1});
            } 
            
            if (r > 0 && image[r - 1][c] == image[r][c] && !used[r - 1][c]) {
                q.push({r - 1, c});
            } 
            
            if (c > 0 && image[r][c - 1] == image[r][c] && !used[r][c - 1]) {
                q.push({r, c - 1});
            } 
        }
        vector<vector<int>> ans = image;
        for (auto& [r, c] : component) {
            ans[r][c] = newColor;
        }
        return ans;
    }
};
