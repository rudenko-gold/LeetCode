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
    void dfs(TreeNode* root, int sum, vector<int>& a) {
        if (!root) {
            return;
        } else if (root->left || root->right) {
            a.push_back(root->val);
            if (root->left) {
                dfs(root->left, sum - root->val, a);
            }
            if (root->right) {
                dfs(root->right, sum - root->val, a);
            }
            a.pop_back();
        } else {
            if (sum == root->val) {
                a.push_back(root->val);
                ans.push_back(a);
                a.pop_back();
            }
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> a;
        dfs(root, sum, a);
        return ans;
    }
    
    vector<vector<int>> ans;
};
