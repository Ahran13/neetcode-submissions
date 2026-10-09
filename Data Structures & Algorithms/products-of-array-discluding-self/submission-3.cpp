class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n, 1);

        int leftP = 1, rightP = 1;

        // First pass: prefix products
        for (int i = 0; i < n; i++) {
            output[i] = leftP;
            leftP *= nums[i];
        }

        // Second pass: suffix products
        for (int i = n - 1; i >= 0; i--) {
            output[i] *= rightP;
            rightP *= nums[i];
        }

        return output;
    }
};
