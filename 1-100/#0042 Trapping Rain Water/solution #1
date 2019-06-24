class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> maxFromLeft(height.size(), 0);
        vector<int> maxFromRight(height.size(), 0);
        int ans = 0;
        int n = height.size();
        if (n == 0) {
            return 0;
        }
        maxFromLeft[0] = height[0];
        for (int i = 1; i < n; i++) {
            maxFromLeft[i] = max(maxFromLeft[i - 1], height[i]);   
        }
        
        maxFromRight[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            maxFromRight[i] = max(maxFromRight[i + 1], height[i]);
        }
        
        for (int i = 1; i < n - 1; i++) {
            ans += max(0, min(maxFromRight[i + 1], maxFromLeft[i - 1]) - height[i]);
        }
        return ans;
    }
};
