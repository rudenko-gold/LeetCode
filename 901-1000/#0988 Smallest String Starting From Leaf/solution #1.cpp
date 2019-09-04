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
    string ans = "";
    string curr = "";
    
    void dfs(TreeNode* root) {
        if (root) {
            curr += char(root->val + 'a');
            if (!root->left && !root->right) {
                string rev = curr;
                reverse(rev.begin(), rev.end());
                if (ans == "") {
                    ans = rev;
                } else {
                    ans = min(ans, rev);
                }
            }
            dfs(root->left);
            dfs(root->right);
            curr.pop_back();
        }
    }
    
    string smallestFromLeaf(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
