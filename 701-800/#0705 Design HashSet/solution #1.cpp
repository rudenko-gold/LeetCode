class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() : data(MAXN, false) {
        
    }
    
    /** value will always be non-negative. */
    void add(int key) {
        data[key] = true;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    bool contains(int key) {
        return data[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        data[key] = false;
    }
    
    const int MAXN = 1000001;
    vector<bool> data;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
