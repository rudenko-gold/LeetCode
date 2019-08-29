struct ItemById {
    int id;
    int val;
};

struct ItemByVal {
    int id;
    int val;
};

bool operator<(const ItemById& lhs, const ItemById& rhs) {
    return lhs.id > rhs.id;
}

bool operator<(const ItemByVal& lhs, const ItemByVal& rhs) {
    if (lhs.val != rhs.val) {
        return lhs.val > rhs.val;
    }

    return lhs.id > rhs.id;
}

class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {
        stack.insert({ last_id, x });
        heap.insert({ last_id, x });
        last_id++;
    }
    
    int pop() {
        auto it = stack.begin();
        int ret = it->val;
        heap.erase({ it->id, it->val });
        stack.erase(it);
        return ret;
    }
    
    int top() {
        return stack.begin()->val;
    }
    
    int peekMax() {
        return heap.begin()->val;
    }
    
    int popMax() {
        auto it = heap.begin();
        int ret = it->val;
        stack.erase({ it->id, it->val });
        heap.erase(it);
        return ret;
    }
    
    set<ItemById> stack;
    set<ItemByVal> heap;
    
    int last_id = 0;
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
