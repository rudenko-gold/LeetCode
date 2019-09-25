class Solution {
public:
    void dfs(int v) {
        used[v] = true;
        
        for (auto to : graph[v]) {
            if (!used[to]) {
                dfs(to);
            }
        }
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        used.resize(n, false);
        
        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                dfs(i);
                ans++;
            }
        }
        return ans;
    }
    vector<bool> used;
    vector<vector<int>> graph;
};
