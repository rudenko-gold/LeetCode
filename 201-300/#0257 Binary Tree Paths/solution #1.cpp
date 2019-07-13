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
    void addToAns(const vector<int>& a) {
        string res = "";
        for (int i = 0; i < a.size() - 1; i++) {
            res += to_string(a[i]) + "->";
        }
        res += to_string(a.back());
        ans.push_back(res);
    }
    
    void dfs(TreeNode* root, vector<int>& a) {
        if (root) {
            if (root->left || root->right) {
                a.push_back(root->val);
                if (root->left) {
                    dfs(root->left, a);
                }
                if (root->right) {
                    dfs(root->right, a);
                }
                
                a.pop_back();
            } else {
                a.push_back(root->val);
                addToAns(a);
                a.pop_back();
            }
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> a;
        dfs(root, a);
        return ans;
    }
    
    vector<string> ans;
};
