/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, int level = 0) {
        if (root) {
            levels[level].push_back(root->val);
            dfs(root->left, level + 1);
            dfs(root->right, level + 1);
        }
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(root);
        for (int i = 0; ;i++) {
            if (levels[i].size() == 0) {
                break;
            }
            ans.push_back(levels[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    unordered_map<int, vector<int>> levels;
};
