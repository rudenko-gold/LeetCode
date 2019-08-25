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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s) {
            if (isEqual(s, t)) {
                return true;
            } else {
                return isSubtree(s->left, t) || isSubtree(s->right, t);
            }
        }
        return false;
    }
    
    bool isEqual(TreeNode* root1, TreeNode* root2) {
        if (root1 && root2) {
            return root1->val == root2->val &&
                isEqual(root1->left, root2->left) &&
                isEqual(root1->right, root2->right);
        } else if (!root1 && !root2) {
            return true;
        } else {
            return false;
        }
    }
};
