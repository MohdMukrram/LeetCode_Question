class Solution {
public:
    bool wordPattern(string pattern, string s) {

        vector<string> words;
        string word = "";

        // Split string into words
        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == ' ') {
                words.push_back(word);
                word = "";
            }
            else {
                word += s[i];
            }
        }

        // Number of pattern characters and words must match
        if (pattern.size() != words.size()) return false;

        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;

        for (int i = 0; i < pattern.size(); i++) {

            char ch = pattern[i];
            string w = words[i];

            // character -> word
            if (mp1.count(ch) && mp1[ch] != w) return false;

            // word -> character
            if (mp2.count(w) && mp2[w] != ch) return false;

            mp1[ch] = w;
            mp2[w] = ch;
        }

        return true;
    }
};