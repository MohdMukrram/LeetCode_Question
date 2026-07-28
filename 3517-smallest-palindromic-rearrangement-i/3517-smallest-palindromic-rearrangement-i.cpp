class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        string left = "", mid = "";

        for (int i = 0; i < 26; ++i) {
            if (freq[i] % 2 == 1) {
                if (!mid.empty()) return ""; // More than 1 odd count → invalid, but problem says input is palindromic
                mid += (char)('a' + i);
            }
            left += string(freq[i] / 2, 'a' + i);
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};