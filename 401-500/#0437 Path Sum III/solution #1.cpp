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
    void dfs(TreeNode* root, int sum) {
        if (root) {
            if (pref.empty()) {
                pref.push_back(root->val);
            } else {
                pref.push_back(pref.back() + root->val);
            }
            pref_cnt[pref.back()]++;
            if (sum == 0) {
                ans += pref_cnt[pref.back() - sum] - 1;
            } else {
                ans += pref_cnt[pref.back() - sum];
            }

            dfs(root->left, sum);
            dfs(root->right, sum);

            pref_cnt[pref.back()]--;
            pref.pop_back();
        }
    }
    
    int pathSum(TreeNode* root, int sum) {
        pref_cnt[0] = 1;
        dfs(root, sum);
        return ans;
    }
    
    unordered_map<int, int> pref_cnt;
    vector<int> pref;
    int ans = 0;
};
