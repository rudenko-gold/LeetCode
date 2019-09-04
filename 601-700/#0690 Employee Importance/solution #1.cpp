/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int dfs(int id) {
        int ans = graph[id]->importance;
        for (auto sub : graph[id]->subordinates) {
            ans += dfs(sub);
        }
        return ans;
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        for (int i = 0; i < employees.size(); i++) {
            graph[employees[i]->id] = employees[i];
        }
        return dfs(id);
    }
    
    unordered_map<int, Employee*> graph;
};
