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
    void dfs(TreeNode* root, vector<int>& vals) {
        if (root) {
            dfs(root->left, vals);
            vals.push_back(root->val);
            dfs(root->right, vals);
        }
    }
    
    int getMinimumDifference(TreeNode* root) {
        vector<int> nodes;
        dfs(root, nodes);
        int ans = numeric_limits<int>::max();
        
        for (int i = 1; i < nodes.size(); ++i) {
            ans = min(ans, nodes[i] - nodes[i - 1]);
        }
        return ans;
    }
};
