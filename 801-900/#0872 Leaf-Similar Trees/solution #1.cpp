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
    void dfs(TreeNode* node, vector<int>& leafs) {
        if (node) {
            if (!node->left && !node->right) {
                leafs.push_back(node->val);
            } else {
                dfs(node->left, leafs);
                dfs(node->right, leafs);
            }
        }
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {        
        vector<int> leafs1, leafs2;
        
        dfs(root1, leafs1);
        dfs(root2, leafs2);
        
        return leafs1 == leafs2;
    }

};
