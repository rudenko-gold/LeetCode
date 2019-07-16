class Solution {
public:
    int maxArea(vector<int>& height) {
        int pointerLeft = 0;
        int pointerRight = height.size() - 1;
        int ans = 0;
        
        while (pointerLeft != pointerRight) {
            ans = max(ans, (pointerRight - pointerLeft) 
                * min(height[pointerLeft], height[pointerRight])); 
            if (height[pointerLeft] < height[pointerRight]) {
                pointerLeft++;
            } else {
                pointerRight--;
            }
        }
        
        return ans;
    }
};
