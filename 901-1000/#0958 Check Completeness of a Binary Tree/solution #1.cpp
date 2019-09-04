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
    int max_idx = 0;
    int cnt = 0;
    void dfs(TreeNode* root, int idx = 1) {
        if (root) {
            cnt++;
            if (idx > 100) {
                cnt = 0;
                return;
            }
            max_idx = max(idx, max_idx);
            dfs(root->left, idx * 2);
            dfs(root->right, idx * 2 + 1);
        }
    }
    
    bool isCompleteTree(TreeNode* root) {
        dfs(root);
        return max_idx == cnt;
    }
};
