class Solution {
public:
    int solve(string &s, int l, int r, int k) {
        // substring length < k cannot be valid
        if (r - l + 1 < k) return 0;

        vector<int> freq(26, 0);
        for (int i = l; i <= r; i++)
            freq[s[i] - 'a']++;

        // Find an invalid character (frequency < k)
        for (int i = l; i <= r; i++) {
            if (freq[s[i] - 'a'] < k) {
                int j = i + 1;
                // Skip consecutive invalid characters
                while (j <= r && freq[s[j] - 'a'] < k)
                    j++;

                return max(solve(s, l, i - 1, k),
                           solve(s, j, r, k));
            }
        }

        // Every character appears at least k times
        return r - l + 1;
    }

    int longestSubstring(string s, int k) {
        return solve(s, 0, s.size() - 1, k);
    }
};