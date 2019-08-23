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
    void dfs(TreeNode* root, TreeNode* parent, int x, int y, int curr_depth = 0) {
        if (root) {
            if (root->val == x) {
                x_depth = curr_depth;
                x_parent = parent;
            } else if (root->val == y) {
                y_depth = curr_depth;
                y_parent = parent;
            }
            
            dfs(root->left, root, x, y, curr_depth + 1);
            dfs(root->right, root, x, y, curr_depth + 1);
        }
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, nullptr, x, y);
        return (x_depth == y_depth) && (x_parent != y_parent);
    }
    
    int x_depth, y_depth;
    TreeNode* x_parent;
    TreeNode* y_parent;

};
