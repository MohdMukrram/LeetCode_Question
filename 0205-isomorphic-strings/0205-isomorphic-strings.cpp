class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;

        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;

        for (int i = 0; i < s.size(); i++) {

            char a = s[i];
            char b = t[i];

            // s -> t mapping
            if (mp1.count(a) && mp1[a] != b)
                return false;

            // t -> s mapping
            if (mp2.count(b) && mp2[b] != a)
                return false;

            mp1[a] = b;
            mp2[b] = a;
        }

        return true;
    }
};