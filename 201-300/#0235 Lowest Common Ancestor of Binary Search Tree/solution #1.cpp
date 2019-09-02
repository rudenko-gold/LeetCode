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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root) { 
            int p_val = p->val;
            int q_val = q->val;

            if (p_val < root->val && q_val < root->val) {
                return lowestCommonAncestor(root->left, p, q);
            } else if (p_val > root->val && q_val > root->val) {
                return lowestCommonAncestor(root->right, p, q);
            } else {
                return root;
            }
        } else {
            return nullptr;
        }
    }
};
