class Solution {
public:
    int n, m;

    int solve(vector<vector<char>>& arr, int i, int j,vector<vector<int>>& dp) {
        if (i >= n || j >= m || arr[i][j] == '0') return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int down = solve(arr, i + 1, j, dp);
        int right = solve(arr, i, j + 1, dp);
        int diagonal = solve(arr, i + 1, j + 1, dp);

        return dp[i][j] = 1 + min({down, right, diagonal});
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        n = matrix.size();
        m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int mx = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mx = max(mx, solve(matrix, i, j, dp));
            }
        }

        return mx * mx;
    }
};