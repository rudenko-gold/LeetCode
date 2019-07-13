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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        } else if (!p) {
            return false;
        } else if (!q) {
            return false;
        }
        
        bool ans = p->val == q->val;
        ans = ans && isSameTree(p->left, q->left);
        ans = ans && isSameTree(p->right, q->right);
        return ans;
    }
};
