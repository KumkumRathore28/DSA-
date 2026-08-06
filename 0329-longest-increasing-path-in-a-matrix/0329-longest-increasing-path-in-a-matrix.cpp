class Solution {
public:
    int m, n;
    vector<vector<int>> dp;

    int dfs(vector<vector<int>>& matrix, int i, int j) {

        if (dp[i][j] != 0)
            return dp[i][j];

        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};

        int ans = 1;

        for (int k = 0; k < 4; k++) {

            int ni = i + dx[k];
            int nj = j + dy[k];

            if (ni >= 0 && nj >= 0 && ni < m && nj < n &&
                matrix[ni][nj] > matrix[i][j]) {

                ans = max(ans, 1 + dfs(matrix, ni, nj));
            }
        }

        return dp[i][j] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {

        m = matrix.size();
        n = matrix[0].size();

        dp.assign(m, vector<int>(n, 0));

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                ans = max(ans, dfs(matrix, i, j));
            }
        }

        return ans;
    }
};