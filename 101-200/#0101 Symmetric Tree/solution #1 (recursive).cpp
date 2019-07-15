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
    bool dfs(TreeNode* root1, TreeNode* root2) {
        if (root1 && root2) {
            if (root1->val != root2->val) {
                return false;
            } else {
                return dfs(root1->left, root2->right) &&
                    dfs(root1->right, root2->left);
            }
        } else if (!root1 && !root2) {
            return true;
        } else {
            return false;
        }
    }
    
    bool isSymmetric(TreeNode* root) {
        if (root) {
            return dfs(root->left, root->right);
        } else {
            return true;
        }
    }
};
