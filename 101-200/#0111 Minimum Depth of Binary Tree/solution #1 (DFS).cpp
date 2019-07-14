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
    int minDepth(TreeNode* root) {
        if (root) {
            int r = numeric_limits<int>::max();
            int l = r;
            if (root->left) {
                l = minDepth(root->left);
            }
            if (root->right) {
                r = minDepth(root->right);
            }
            if (min(l, r) == numeric_limits<int>::max()) {
                return 1;
            } else {
                return min(l, r) + 1;
            }
        } else {
            return 0;
        }
    }
};
