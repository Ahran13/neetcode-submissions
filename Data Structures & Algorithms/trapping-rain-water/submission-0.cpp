class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int water = 0;

        while (l < r) {
            leftMax = max(leftMax, height[l]);
            rightMax = max(rightMax, height[r]);

            if (leftMax <= rightMax) {
                water += leftMax - height[l];
                l++;
            } else {
                water += rightMax - height[r];
                r--;
            }
        }

        return water;
    }
};