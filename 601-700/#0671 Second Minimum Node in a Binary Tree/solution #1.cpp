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
    void dfs(TreeNode* root) {
        if (root) {
            if (root->left && root->right) {
                dfs(root->left);
                dfs(root->right);
            } else {
                s.insert(root->val);
                if (s.size() > 2) {
                    s.erase(--s.end());
                }
            }
        }    
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        dfs(root);
        if (s.size() < 2) {
            return -1;
        }
        return *(--s.end());
    }
    
    set<int> s;
};
