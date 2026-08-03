class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();

        if (n + m != s3.size())
            return false;

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        // dp[i][j] means:
        // Can we form first i+j characters of s3
        // using first i characters of s1
        // and first j characters of s2?

        dp[0][0] = true;

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {

                if (i == 0 && j == 0)
                    continue;

                // Take current character from s1
                if (i > 0 && s1[i - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }

                // Take current character from s2
                if (j > 0 && s2[j - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
                }
            }
        }

        return dp[n][m];
    }
};