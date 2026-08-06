class Solution {
public:
    int solve(vector<int>& arr, int i, int j, vector<vector<int>>& dp) {
        if (i > j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int ans = 0;

        for (int k = i; k <= j; k++) {
            ans = max(ans,
                solve(arr, i, k - 1, dp) +
                solve(arr, k + 1, j, dp) +
                arr[i - 1] * arr[k] * arr[j + 1]
            );
        }

        return dp[i][j] = ans;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));

        return solve(nums, 1, n, dp);
    }
};