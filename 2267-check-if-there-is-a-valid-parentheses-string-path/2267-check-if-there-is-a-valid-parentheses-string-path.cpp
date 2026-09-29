class Solution {
public:
    bool hasValidPath(auto& A) {
        int m = A.size(), n = A[0].size();

        if ((m + n - 1) & 1 || (A[0][0] & 1))
            return 0;

        vector<bitset<102>> dp(n + 1);
        dp[1].set(0);

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                dp[j + 1] = ((dp[j + 1] | dp[j]) << 1) >>
                            ((A[i][j] & 1) << 1);

        return dp[n].test(0);
    }
};