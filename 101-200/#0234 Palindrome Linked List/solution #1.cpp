/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(ListNode* node) {
        if (node) {
            dfs(node->next);
            if (node->val != start->val) {
                ans = false;
            } else {
                start = start->next;
            }
        }
    }
    
    bool isPalindrome(ListNode* head) {
        start = head;
        ans = true;
        dfs(head);
        return ans;
    }
    
    ListNode* start;
    bool ans;
};
