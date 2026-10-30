class Solution {
public:
    int findMin(vector<int> &nums) {
        int low = 0, high = nums.size() - 1, minn = INT_MAX, prevHigh = nums.size() - 1;
        int n = nums.size();
        if (nums[low] <= nums[high])
            return nums[low];
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[mid + 1]) {
                minn = nums[mid + 1];
                break;
            }

            else 
            {
                if (nums[low] > nums[high])
                {
                    prevHigh = high;
                    high = mid - 1;
                }

                else 
                {
                    high = prevHigh;
                    low = mid + 1;
                }
                minn = min(minn, nums[mid]);
            }
        }
        return minn;
    }
};
