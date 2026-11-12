class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {

        int sum = 0;
        int count = 0;

        for(int i = 0; i < k; i++) {
            sum += arr[i];
        }

        int target = k * threshold;

        if(sum >= target) {
            count++;
        }

        for(int i = k; i < arr.size(); i++) {

            sum = sum - arr[i-k] + arr[i];

            if(sum >= target) {
                count++;
            }
        }
        return count;
    }
};
