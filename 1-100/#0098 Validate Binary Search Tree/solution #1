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
    bool dfs(TreeNode* root, vector<int>& ans) {
        if (root) {
            dfs(root->left, ans);
            ans.push_back(root->val);
            dfs(root->right, ans);
        }
    }
    
    bool isValidBST(TreeNode* root) {
        vector<int> bst;
        dfs(root, bst);
        for (int i = 1; i < bst.size(); i++) {
            if (bst[i] <= bst[i - 1]) {
                return false;
            }
        }
        return true;
    }
};
