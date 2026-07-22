class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        int row = -1;

        int low = 0, high = m - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (target >= matrix[mid][0] && target <= matrix[mid][n - 1]) {
                row = mid;
                break;
            }
            else if (target < matrix[mid][0]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        if (row == -1)
            return false;

        low = 0;
        high = n - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (matrix[row][mid] == target)
                return true;

            else if (matrix[row][mid] < target)
                low = mid + 1;

            else
                high = mid - 1;
        }

        return false;
    }
};