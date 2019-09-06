class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        multiset<pair<int, int>> heap;
        
        for (int el : arr) {
            heap.insert( { abs(x - el), el });
            if (heap.size() > k) {
                heap.erase(--heap.end());
            }
        }
        
        vector<int> ans;
        ans.reserve(heap.size());
        for (auto& [diff, el] : heap) {
            ans.push_back(el);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
