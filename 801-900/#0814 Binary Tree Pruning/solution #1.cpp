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
    int dfs(TreeNode* root) {
        if (root) {
            int left = dfs(root->left);
            int right = dfs(root->right);
            if (left == 0) {
                root->left = nullptr;
            } 
            if (right == 0) {
                root->right = nullptr;
            }
            
            return left + right + root->val;
        } else {
            return 0;
        }
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        dfs(root);
        if (root->val == 0 && !root->left && !root->right) {
            return nullptr;
        } else {
            return root;
        }
    }
};
