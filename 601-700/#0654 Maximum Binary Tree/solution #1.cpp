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
    TreeNode* construct(vector<int>& nums, int l, int r) {
        if (r - l <= 0) {
            return nullptr;
        }
        
        int max_pos = max_element(nums.begin() + l, nums.begin() + r) - nums.begin();
        TreeNode* node = new TreeNode(nums[max_pos]);
        node->left = construct(nums, l, max_pos);
        node->right = construct(nums, max_pos + 1, r);
        return node;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums, 0, nums.size());
    }
};
