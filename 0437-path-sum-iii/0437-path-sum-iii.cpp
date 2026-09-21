class Solution {
public:

    int dfs(TreeNode* root, long long currentSum,
            long long targetSum,
            unordered_map<long long, int>& prefixSum) {

        if (root == NULL) {
            return 0;
        }

        currentSum += root->val;

        int count = 0;

        if (prefixSum.find(currentSum - targetSum) != prefixSum.end()) {
            count = prefixSum[currentSum - targetSum];
        }

        prefixSum[currentSum]++;

        count += dfs(root->left, currentSum, targetSum, prefixSum);
        count += dfs(root->right, currentSum, targetSum, prefixSum);

        prefixSum[currentSum]--;

        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {

        unordered_map<long long, int> prefixSum;

        prefixSum[0] = 1;

        return dfs(root, 0, targetSum, prefixSum);
    }
};