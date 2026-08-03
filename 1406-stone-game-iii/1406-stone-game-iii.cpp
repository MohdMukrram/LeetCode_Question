class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> dp(n + 3, 0);

        // dp[i] = maximum score difference
        // current player - opponent
        for (int i = n - 1; i >= 0; i--) {
            int sum = 0;

            dp[i] = INT_MIN;

            // Take 1, 2, or 3 stones
            for (int k = 1; k <= 3 && i + k <= n; k++) {
                sum += stoneValue[i + k - 1];

                dp[i] = max(dp[i], sum - dp[i + k]);
            }
        }

        if (dp[0] > 0) return "Alice";
        else if (dp[0] < 0) return "Bob";
        else return "Tie";
    }
};