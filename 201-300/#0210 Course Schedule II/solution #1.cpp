class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if (canFinish(numCourses, prerequisites)) {
            fill(used.begin(), used.end(), 0);
            for (int i = 0; i < numCourses; ++i) {
                if (used[i] == 0) {
                    dfs(i);
                }
            }
            return order;
        } else {
            return {};
        }
    }
    
    void dfs(int v) {
        used[v] = 1;
        for (auto to : graph[v]) {
            if (!used[to]) {
                dfs(to);
            }
        }
        order.push_back(v);
    }
    
    void findCycle(int v) {
        used[v] = 1;
        
        for (auto to : graph[v]) {
            if (used[to] == 1) {
                ans = false;
            } else if (used[to] == 0) {
                findCycle(to);
            }
        }
        
        used[v] = 2;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph.resize(numCourses);
        used.resize(numCourses, 0);
        
        for (auto& edge : prerequisites) {
            graph[edge[0]].push_back(edge[1]);
        }
        
        for (int i = 0; i < numCourses; ++i) {
            if (used[i] == 0) {
                findCycle(i);
            }
        }
        
        return ans;
    }
    
    bool ans = true;
    vector<vector<int>> graph;
    vector<int> used; // 0 - not used, 1 - used in current recursion, 2 - used previosly
    vector<int> order;
};
