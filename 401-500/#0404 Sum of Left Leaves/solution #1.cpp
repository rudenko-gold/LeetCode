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
    void dfs(TreeNode* root) {
        if (root) {
            if (isLeaf(root->left)) {
                ans += root->left->val;
            }
            dfs(root->left);
            dfs(root->right);
        }
    }
    
    bool isLeaf(TreeNode* root) {
        if (root) {
            if (!root->left && !root->right) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        dfs(root);
        return ans;
    }
    int ans = 0;
};
