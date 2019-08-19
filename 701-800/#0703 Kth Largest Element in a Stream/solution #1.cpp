class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < min(k, (int)nums.size()); i++) {
            heap.insert(nums[nums.size() - 1 - i]);
        }
    }
    
    int add(int val) {
        heap.insert(val);
        if (heap.size() > k) {
            heap.erase(heap.begin());
        }
        return *heap.begin();
    }
    
    multiset<int> heap;
    int k;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
