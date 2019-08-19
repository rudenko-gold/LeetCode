class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        
        if (k == 1) {
            ans.resize(nums.size());
            for (size_t i = 0; i < nums.size(); ++i) {
                ans[i] = nums[i];
            }
            return ans;
        }
        
        multiset<int> firstHalf, secondHalf;
        int halfSize = k / 2;
        
        for (int i = 0; i < k; i++) {
            firstHalf.insert(nums[i]);
            if (firstHalf.size() > halfSize) {
                auto last = --firstHalf.end();
                secondHalf.insert(*last);
                firstHalf.erase(last);
            }
        }
        
        int l = 0;
        int r = k;
        
        while (r < nums.size()) {
            if (k % 2 == 0) {
                double med = (*(--firstHalf.end()) + *secondHalf.begin() * 1.0) / 2.0;
                ans.push_back(med);
            } else {
                ans.push_back(*secondHalf.begin());
            }
            
            int leftElement = nums[l];
            l++;
            int rightElement = nums[r];
            r++;
            
            if (auto it = firstHalf.find(leftElement); it != firstHalf.end()) {
                firstHalf.erase(it);
            } else {
                secondHalf.erase(secondHalf.find(leftElement));
            }
            
            if (rightElement < *secondHalf.begin()) {
                firstHalf.insert(rightElement);
            } else {
                secondHalf.insert(rightElement);
            }
            
            if (firstHalf.size() > halfSize) {
                auto it = --firstHalf.end();
                secondHalf.insert(*it);
                firstHalf.erase(it);
            } else if (firstHalf.size() < halfSize) {
                auto it = secondHalf.begin();
                firstHalf.insert(*it);
                secondHalf.erase(it);
            }
        }

        if (k % 2 == 0) {
            double med = (*(--firstHalf.end()) + *secondHalf.begin() * 1.0) / 2.0;
            ans.push_back(med);
        } else {
            ans.push_back(*secondHalf.begin());
        }
        
        return ans;
    }
};
