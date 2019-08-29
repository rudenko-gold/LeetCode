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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (root) {
            if (root->val < L) {
                if (root->right) {
                    root = trimBST(root->right, L, R);
                    return root;
                } else {
                    return nullptr;
                }
            } else if (root->val > R) {
                if (root->left) {
                    root = trimBST(root->left, L, R);
                    return root;
                } else {
                    return nullptr;
                }
            } else {
                root->right = trimBST(root->right, L, R);
                root->left = trimBST(root->left, L, R);
                return root;
            }
        } else {
            return nullptr;
        }
    } 
};
