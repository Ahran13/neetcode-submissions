class Solution {
public:
    int trap(vector<int>& h) {
        int l = 0, r = h.size() - 1;
        int lMax = 0, rMax = 0, water = 0;
        
        while(l < r) {
            lMax = max(lMax, h[l]);
            rMax = max(rMax, h[r]);

            if(lMax <= rMax) {
                water += lMax - h[l];
                l++;
            }
            else {
                water += rMax - h[r];
                r--;
            }
        }
        return water;
    }
};