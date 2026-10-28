class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int low = 0, high = n - 1, row = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (matrix[mid][0] <= target) {
                row = mid;
                low = mid + 1;
            } 
            else 
                high = mid - 1;
        }

        if (row == -1)
            return false;

        low = 0, high = m - 1;
        int mid = (m - 1) / 2;

        while(low <= high) {
            if (matrix[row][mid] == target)
                return true;
            else if (matrix[row][mid] < target) {
                low = mid + 1;
                mid = low + (high - low) / 2;
            }
            else {
                high = mid - 1;
                mid = low + (high - low) / 2;
            }
        }
        
        return false;
    }
};
