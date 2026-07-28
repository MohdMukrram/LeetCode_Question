class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0;

        while (i < n) {
            int start = i;

            // move to end of word
            while (i < n && s[i] != ' ') {
                i++;
            }

            int end = i - 1;

            // reverse the word
            while (start < end) {
                swap(s[start], s[end]);
                start++;
                end--;
            }

            i++; // skip space
        }

        return s;
    }
};