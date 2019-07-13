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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        ListNode* node = head;
        int pos = 0;
        while (curr) {
            if (pos >= n + 1) {
                node = node->next;
            }
            pos++;
            curr = curr->next;
        }
        if (pos == n) {
            head = head->next;
        } else if (node->next) {
            node->next = node->next->next;
        } 
        
        return head;
    }
};
