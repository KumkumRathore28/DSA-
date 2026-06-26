class Solution {
public:
    int mergeSort(vector<long long>& prefix, int left, int right,
                  int lower, int upper) {

        if (left >= right)
            return 0;

        int mid = left + (right - left) / 2;

        int count = mergeSort(prefix, left, mid, lower, upper)
                  + mergeSort(prefix, mid + 1, right, lower, upper);

        int low = mid + 1;
        int high = mid + 1;

        for (int i = left; i <= mid; i++) {

            while (low <= right &&
                   prefix[low] - prefix[i] < lower)
                low++;

            while (high <= right &&
                   prefix[high] - prefix[i] <= upper)
                high++;

            count += high - low;
        }

        vector<long long> temp;

        int i = left;
        int j = mid + 1;

        while (i <= mid && j <= right) {
            if (prefix[i] <= prefix[j])
                temp.push_back(prefix[i++]);
            else
                temp.push_back(prefix[j++]);
        }

        while (i <= mid)
            temp.push_back(prefix[i++]);

        while (j <= right)
            temp.push_back(prefix[j++]);

        for (int k = left; k <= right; k++)
            prefix[k] = temp[k - left];

        return count;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {

        int n = nums.size();

        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];

        return mergeSort(prefix, 0, n, lower, upper);
    }
};