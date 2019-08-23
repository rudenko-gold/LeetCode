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
            dfs(root->left);
            dfs(root->right);
            if (root->left && root->right) {
                if (root->left->val > root->right->val) {
                    swap(root->left, root->right);
                } 
            } else if (root->right) {
                swap(root->left, root->right);
            }
        }
    }
    
    bool isEqual(TreeNode* root1, TreeNode* root2) {
        if (root1 && root2) {
            return root1->val == root2->val &&
                isEqual(root1->left, root2->left) &&
                isEqual(root1->right, root2->right);
        } else if (!root1 && !root2) {
            return true;
        } else {
            return false;
        }
    }
    
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        dfs(root1);
        dfs(root2);
        
        return isEqual(root1, root2);
    }
};
