class Solution {
public:
    int m, n;

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& vis, int i, int j) {
        vis[i][j] = true;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if (ni >= 0 && nj >= 0 && ni < m && nj < n &&
                !vis[ni][nj] &&
                heights[ni][nj] >= heights[i][j]) {

                dfs(heights, vis, ni, nj);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // Pacific
        for (int i = 0; i < m; i++)
            dfs(heights, pacific, i, 0);

        for (int j = 0; j < n; j++)
            dfs(heights, pacific, 0, j);

        // Atlantic
        for (int i = 0; i < m; i++)
            dfs(heights, atlantic, i, n - 1);

        for (int j = 0; j < n; j++)
            dfs(heights, atlantic, m - 1, j);

        vector<vector<int>> ans;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
};