class Solution {
public:
    int dp[1001][1001];

    bool solve(string& s, int i, int j) {
        // Base cases
        if (i >= j) return true;
        if (dp[i][j] != -1) return dp[i][j];

        // Recursive case: Check if s[i] == s[j] and the inner substring is a palindrome
        if (s[i] == s[j]) {
            return dp[i][j] = solve(s, i + 1, j - 1);
        } else {
            return dp[i][j] = false;
        }
    }

    string longestPalindrome(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp)); // Initialize dp with -1
        int maxlen = 0;
        int sp = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (solve(s, i, j)) {
                    if (j - i + 1 > maxlen) {
                        maxlen = j - i + 1;
                        sp = i;
                    }
                }
            }
        }
        return s.substr(sp, maxlen);
    }
};