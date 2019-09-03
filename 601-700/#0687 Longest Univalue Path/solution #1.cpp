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
    int ans = 0;
    
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return ans;
    }
    
    int dfs(TreeNode* root) {
        if (root) {
            int left = dfs(root->left);
            int right = dfs(root->right);
            
            int aLeft = 0;
            int aRight = 0;
            if (root->left && root->left->val == root->val) {
                aLeft = left + 1;
            }
            
            if (root->right && root->right->val == root->val) {
                aRight = right + 1;
            }
            
            ans = max(ans, aLeft + aRight);
            
            return max(aLeft, aRight);
        } else {
            return 0;
        }
    }
};
