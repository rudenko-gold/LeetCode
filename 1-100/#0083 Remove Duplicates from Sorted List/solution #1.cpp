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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        while (curr) {
            ListNode* n = curr->next;
            while (n && n->val == curr->val) {
                n = n->next;
            }
            curr->next = n;
            curr = curr->next;
        }

        return head;
    }
};
