class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();

        if (n == 0)
            return 0;

        int left = 0;
        int maximum = 1;

        for (int right = 1; right < n; right++) {

            if (nums[right] <= nums[right - 1]) {
                left = right;
            }

            int windowLength = right - left + 1;

            maximum = max(maximum, windowLength);
        }

        return maximum;
    }
};