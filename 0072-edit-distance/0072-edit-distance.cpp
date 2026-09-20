class Solution {
public:

    int solve(string &word1, string &word2, int i, int j,
              vector<vector<int>> &dp) {

        if (i == 0) {
            return j;
        }

        if (j == 0) {
            return i;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (word1[i - 1] == word2[j - 1]) {
            return dp[i][j] = solve(word1, word2, i - 1, j - 1, dp);
        }

        int insert = solve(word1, word2, i, j - 1, dp);
        int remove = solve(word1, word2, i - 1, j, dp);
        int replace = solve(word1, word2, i - 1, j - 1, dp);

        return dp[i][j] = 1 + min({
            insert,
            remove,
            replace
        });
    }

    int minDistance(string word1, string word2) {

        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> dp(m + 1,
                               vector<int>(n + 1, -1));

        return solve(word1, word2, m, n, dp);
    }
};