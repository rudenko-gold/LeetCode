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
    void push_back(ListNode* node, int val) {
        node->next = new ListNode(val);
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        ListNode* ans = new ListNode(0);
        ListNode* curr = ans;
        int ost = 0;
        while (curr1 || curr2) {
            int val = ost;
            if (curr1) {
                val += curr1->val;
                curr1 = curr1->next;
            }
            if (curr2) {
                val += curr2->val;
                curr2 = curr2->next;
            }
            
            push_back(curr, val % 10);
            curr = curr->next;
            ost = val / 10;
        }
        if (ost > 0) {
            push_back(curr, ost);
            curr = curr->next;
        }
            
        return ans->next;
    }
};
