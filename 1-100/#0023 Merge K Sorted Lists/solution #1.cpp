/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct SetNode {
    int item;
    int list_id;
};

bool operator < (const SetNode& lhs, const SetNode& rhs) {
    return lhs.item < rhs.item;
}
    
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        multiset<SetNode> s;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i]) {
                s.insert({ lists[i]->val, i });
            }
        }
        
        while (s.size() > 0) {
            auto it = s.begin();
            int item = it->item;
            int id = it->list_id;
            s.erase(it);
            curr->next = new ListNode(item);
            curr = curr->next;
            
            lists[id] = lists[id]->next;
            if (lists[id]) {
                s.insert({ lists[id]->val, id });
            }
        }
        
        return head->next;
    }
};
