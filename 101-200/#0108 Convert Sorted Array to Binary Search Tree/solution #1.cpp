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
    void sortedArrayToBST(vector<int>& nums, TreeNode* node, int l, int r) {
        if (l < r) {
            int m = (l + r) / 2;
            node->val = nums[m];
            if (l < m) {
                node->left = new TreeNode(0);
                sortedArrayToBST(nums, node->left, l, m);    
            }
            if (m + 1 < r) {
                node->right = new TreeNode(0);
                sortedArrayToBST(nums, node->right, m + 1, r); 
            }
        } else if (l + 1 == r) {
            node->val = nums[l];
        }
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(0);
        sortedArrayToBST(nums, root, 0, nums.size());
        return root;
    }
};
