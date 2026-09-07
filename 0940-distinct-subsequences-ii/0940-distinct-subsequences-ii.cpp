class Solution {
public:
    const long long MOD = 1e9 + 7;

    vector<long long> dp;

    long long solve(int i, string &s) {

        if (i < 0)
            return 1;

        if (dp[i] != -1)
            return dp[i];

        long long ans = (2 * solve(i - 1, s)) % MOD;

        // Find previous occurrence of s[i]
        int prev = -1;

        for (int j = i - 1; j >= 0; j--) {
            if (s[j] == s[i]) {
                prev = j;
                break;
            }
        }

        // Remove duplicates
        if (prev != -1) {
            ans = (ans - solve(prev - 1, s) + MOD) % MOD;
        }

        return dp[i] = ans;
    }

    int distinctSubseqII(string s) {

        int n = s.size();

        dp.assign(n, -1);

        // Includes empty subsequence
        long long ans = solve(n - 1, s);

        // Remove empty subsequence
        return (ans - 1 + MOD) % MOD;
    }
};