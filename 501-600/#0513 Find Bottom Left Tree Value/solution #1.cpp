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
    void dfs(TreeNode* root, int depth = 0) {
        if (root) {
            if (depth > max_depth) {
                ans = root->val;
                max_depth = depth;
            }
            dfs(root->left, depth + 1);
            dfs(root->right, depth + 1);
        }
    } 
    
    int findBottomLeftValue(TreeNode* root) {
        dfs(root);
        return ans;
    }
    
    int max_depth = -1;
    int ans = 0;
};
