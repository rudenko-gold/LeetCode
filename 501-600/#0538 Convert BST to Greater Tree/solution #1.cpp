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
    int greaterSum = 0, prev = 0, cnt = 0;
    
    void dfs(TreeNode* root) {
        if (root) {
            dfs(root->right);
            if (root->val == prev) {
                cnt++;
                root->val += greaterSum;
            } else {
                greaterSum += cnt * prev;
                prev = root->val;
                cnt = 1;
                root->val += greaterSum;
            }
            dfs(root->left);    
        }
    }
    
    TreeNode* convertBST(TreeNode* root) {
        dfs(root);
        return root;
    }
};
