class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> heap;
        
        for (int i = 0; i < nums.size(); ++i) {
            heap.insert(nums[i]);
            if (heap.size() > k) {
                heap.erase(heap.begin());
            }
        }
        
        return *heap.begin();
    }
};
