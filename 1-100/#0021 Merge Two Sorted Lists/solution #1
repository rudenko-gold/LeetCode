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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) {
            return nullptr;
        }
        
        ListNode* ans = new ListNode(0);
        ListNode* ansHead = ans;
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        
        while (curr1 || curr2) {
            if (!curr1) {
                ans->val = curr2->val;
                curr2 = curr2->next;
            } else if (!curr2) {
                ans->val = curr1->val;
                curr1 = curr1->next;
            }  else {
                if (curr1->val <= curr2->val) {
                    ans->val = curr1->val;
                    curr1 = curr1->next;
                } else {
                    ans->val = curr2->val;
                    curr2 = curr2->next;
                }
            }
            if (curr1 || curr2) {
                ans->next = new ListNode(0);
                ans = ans->next;
            }
        }
        
        return ansHead;
    }
};
