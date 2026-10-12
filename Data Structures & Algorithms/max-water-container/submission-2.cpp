class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1;
        int maxW = 0;

        while(l < r) {
            int w = (r - l) * min(heights[l], heights[r]);
            maxW = max(maxW, w);

            if (heights[l] == heights[r]) {
                l++;
                r--;
                continue;
            }

            heights[l] < heights[r] ? l++ : r--;
        }
        return maxW;
    }
};
