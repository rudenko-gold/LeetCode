class MyLinkedList {
public:
    struct Node {
        Node* prev;
        Node* next;
        int val;
    };
    
    /** Initialize your data structure here. */
    MyLinkedList() {
        
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index >= 0 && index < size) {
            Node* curr_node = head;
            int curr_index = 0;
            
            while (curr_index != index) {
                curr_node = curr_node->next;
                curr_index++;
            }
            
            return curr_node->val;
        } else {
            return -1;
        }
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        if (size == 0) {
            head = new Node();
            head->val = val;
            tail = head;
        } else {
            Node* new_head = new Node();
            new_head->val = val;
            new_head->next = head;
            head->prev = new_head;
            head = new_head;
        }
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if (size == 0) {
            head = new Node();
            head->val = val;
            tail = head;  
        } else {
            Node* new_tail = new Node();
            new_tail->val = val;
            new_tail->prev = tail;
            tail->next = new_tail;
            tail = new_tail;
        }
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index <= 0) {
            addAtHead(val);
        } else if (index == size) {
            addAtTail(val);
        } else if (index > 0 && index < size) {
            int curr_index = 0;
            Node* curr_node = head;

            while (curr_index != index - 1) {
                curr_node = curr_node->next;
                curr_index++;
            }
            
            Node* new_node = new Node();
            
            new_node->val = val;
            
            new_node->prev = curr_node;
            new_node->next = curr_node->next;
            
            curr_node->next = new_node;
            new_node->next->prev = new_node;
            size++;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (size > 0) {
            if (index == 0) {
                if (size == 1) {
                    delete head;
                    head = nullptr;
                    tail = nullptr;
                } else {
                    head = head->next;
                    delete head->prev;
                    head->prev = nullptr;
                }

                size--;
            } else if (index == size - 1) {
                if (size == 1) {
                    delete head;
                    head = nullptr;
                    tail = nullptr;
                } else {                    
                    tail = tail->prev;
                    delete tail->next;
                    tail->next = nullptr;
                }

                size--;
            } else if (index > 0 && index < size - 1) {
                int curr_index = 0;
                Node* curr_node = head;
                while (curr_index != index) {
                    curr_node = curr_node->next;
                    curr_index++;
                }
                Node* prev = curr_node->prev;
                Node* next = curr_node->next;
                prev->next = next;
                next->prev = prev;
                delete curr_node;
                size--;
            }
        }
    }
    
    Node* head = nullptr;
    Node* tail = nullptr;
    
    int size = 0;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
