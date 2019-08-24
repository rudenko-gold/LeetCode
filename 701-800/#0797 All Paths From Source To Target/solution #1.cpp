class Solution {
public:
    void dfs(int v, vector<vector<int>>& graph, int finish, vector<vector<int>>& ans, vector<int>& path) {
        path.push_back(v);
        if (v == finish) {
            ans.push_back(path);
            path.pop_back();
            return;
        } else {
            for (auto& to : graph[v]) {
                dfs(to, graph, finish, ans, path);
            }
            path.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int start = 0;
        int finish = graph.size() - 1;
        vector<vector<int>> ans;
        vector<int> path;
        
        dfs(0, graph, finish, ans, path);
        return ans;
    }
};
