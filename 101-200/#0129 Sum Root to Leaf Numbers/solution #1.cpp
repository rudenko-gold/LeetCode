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
    int curr = 0;
    void dfs(TreeNode* root) {
        if (root) {
            curr *= 10;
            curr += root->val;
            if (!root->left && !root->right) {
                ans += curr;
            } else {
                dfs(root->left);
                dfs(root->right); 
            }
            curr /= 10;
        }
    }
    
    int sumNumbers(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
