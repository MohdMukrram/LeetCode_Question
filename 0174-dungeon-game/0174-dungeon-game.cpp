class Solution {
public:
    int n, m;

    int solve(vector<vector<int>>& dungeon, int i, int j,vector<vector<int>>& dp) {

        if (i == n - 1 && j == m - 1) return max(1, 1 - dungeon[i][j]);

        if (dp[i][j] != -1) return dp[i][j];

        int down = INT_MAX;
        int right = INT_MAX;

        if (i + 1 < n) down = solve(dungeon, i + 1, j, dp);

        if (j + 1 < m) right = solve(dungeon, i, j + 1, dp);

        int need = min(down, right) - dungeon[i][j];

        return dp[i][j] = max(1, need);
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        n = dungeon.size();
        m = dungeon[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(dungeon, 0, 0, dp);
    }
};