class Solution {
public:
    int n, m;
    int dp[71][71][71];

    int solve(vector<vector<int>>& grid, int i, int j1, int j2) {
        if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return -1e9;

        if (i == n - 1) {
            if (j1 == j2) return grid[i][j1];

            return grid[i][j1] + grid[i][j2];
        }

        if (dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int cherries;

        if (j1 == j2) cherries = grid[i][j1];
        else cherries = grid[i][j1] + grid[i][j2];

        int ans = -1e9;

        for (int d1 = -1; d1 <= 1; d1++) {
            for (int d2 = -1; d2 <= 1; d2++) {
                ans = max(ans, cherries + solve(grid, i + 1, j1 + d1, j2 + d2));
            }
        }

        return dp[i][j1][j2] = ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        memset(dp, -1, sizeof(dp));

        return solve(grid, 0, 0, m - 1);
    }
};