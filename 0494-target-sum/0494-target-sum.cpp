class Solution {
public:

    map<pair<int, int>, int> dp;

    int solve(vector<int>& nums, int index,
              int sum, int target) {

        if (index == nums.size()) {
            return sum == target;
        }

        if (dp.count({index, sum})) {
            return dp[{index, sum}];
        }

        int add = solve(nums, index + 1,
                        sum + nums[index], target);

        int subtract = solve(nums, index + 1,
                             sum - nums[index], target);

        return dp[{index, sum}] = add + subtract;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        return solve(nums, 0, 0, target);
    }
};