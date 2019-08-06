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
    ListNode* middleNode(ListNode* head) {
        if (head) {
            ListNode* curr = head;    
            int listSize = 0;
            while (curr) {
                listSize++;
                curr = curr->next;
            }
            int findIndex = listSize / 2;
            
            curr = head;
            for (int i = 0; i < findIndex; ++i) {
                curr = curr->next;
            }
            return curr;
        } else {
            return nullptr;
        }
    }
};
