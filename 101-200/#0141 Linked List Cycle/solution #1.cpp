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
    bool hasCycle(ListNode *head) {
            if (!head) {
                return false;
            }
        
        	if (!head->next) {
                return false;
            }
            auto slowly = head;
            auto quickly = head->next;

            while (quickly != nullptr) {
                if (slowly->val == quickly->val) {
                    return true;
                }
                slowly = slowly->next;
                quickly = quickly->next;
                if (quickly == nullptr) {
                    return false;
                }
                quickly = quickly->next;
            }

            return false;

    }
};
