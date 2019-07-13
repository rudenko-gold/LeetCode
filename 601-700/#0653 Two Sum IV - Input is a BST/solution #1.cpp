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
    void dfs(TreeNode* root, vector<int>& a) {
        if (root) {
            dfs(root->left, a);
            a.push_back(root->val);
            dfs(root->right, a);
        }
    }
    
    bool findTarget(TreeNode* root, int k) {
        vector<int> a; 
        dfs(root, a);
        for (int i = 0; i < a.size(); ++i) {
            auto it = lower_bound(a.begin(), a.end(), k - a[i]);
            
            if (it != a.end() && it - a.begin() != i && *it == k - a[i]) {
                return true;
            }
        }
        
        return false;
    }
};
