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
    
    int dfs(TreeNode* root) {
        if (root) {
            int left_sum = dfs(root->left);
            int right_sum = dfs(root->right);
            
            ans += abs(left_sum - right_sum);
            return left_sum + right_sum + root->val;
        } else {
            return 0;
        }
    }
    
    int findTilt(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
