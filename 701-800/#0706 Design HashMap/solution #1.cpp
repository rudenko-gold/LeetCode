class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() : data(MAXN, { false, 0 }) {
        
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        data[key].flag = true;
        data[key].value = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        if (data[key].flag) {
            return data[key].value;
        } else {
            return -1;
        }
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        data[key].flag = false;
    }
    
    struct cell {
        bool flag;
        int value;
    };
    
    const int MAXN = 1000001;
    vector<cell> data;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
