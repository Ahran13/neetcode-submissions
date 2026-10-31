class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), mid;
        int low = 0, high = n - 1;
        while(low < high)
        {
            mid = low + (high - low) / 2;
            nums[mid] > nums[high] ? low = mid + 1 : high = mid;
        }
        int pivot = low;
        low = 0, high = n - 1;
        while(low <= high)
        {
            mid = low + (high - low) / 2;
            int actual = (mid + pivot) % n;
            if (target < nums[actual])
                high = mid - 1;
            else if (target > nums[actual])
                low = mid + 1;
            else
                return actual;
        }
        return -1;
    }
};
