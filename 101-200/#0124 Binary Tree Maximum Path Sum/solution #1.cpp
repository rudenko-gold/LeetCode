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
    int ans = numeric_limits<int>::min();
    
    int dfs(TreeNode* root) {
        if (root) {
            int left = max(dfs(root->left), 0);
            int right = max(dfs(root->right), 0);
            
            ans = max(ans, left + right + root->val);
            return root->val + max(left, right);
        } else {
            return 0;
        }
    }
    
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
