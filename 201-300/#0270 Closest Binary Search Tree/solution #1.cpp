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
    int closestValue(TreeNode* root, double target) {
        int ans = root->val;
        while (root) {
            if (abs(root->val - target) < abs(ans - target)) {
                ans = root->val;
            }
            if (target < root->val) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return ans;
    }
};
