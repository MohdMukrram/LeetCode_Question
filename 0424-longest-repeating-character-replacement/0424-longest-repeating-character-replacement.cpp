class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        int i = 0;
        int mx = 0;
        int maxFreq = 0;

        unordered_map<char, int> mp;

        for (int j = 0; j < n; j++) {

            // Add current character
            mp[s[j]]++;

            // Maximum frequency in current window
            maxFreq = max(maxFreq, mp[s[j]]);

            // Number of characters we need to replace
            int windowSize = j - i + 1;
            int changes = windowSize - maxFreq;

            // Invalid window
            while (changes > k) {
                mp[s[i]]--;
                i++;

                windowSize = j - i + 1;
                changes = windowSize - maxFreq;
            }

            // Valid window
            mx = max(mx, j - i + 1);
        }

        return mx;
    }
};