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
    int dfs(TreeNode* root, bool& ans) {
        if (root) {
            int h_left = dfs(root->left, ans);
            int h_right = dfs(root->right, ans);
            if (abs(h_left - h_right) > 1) {
                ans = false;
            }
            return max(h_left, h_right) + 1;
        } else {
            return 0;
        }
    }
    
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        dfs(root, ans);
        return ans;
    }
};
