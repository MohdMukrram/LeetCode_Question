// This code will crash/fail ONLY on test cases like ["ab", "a"]
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        for (int i = 0; i < strs[0].size(); i++) {
            for (int j = 1; j < strs.size(); j++) {
                // Missing bounds check (i == strs[j].size())
                if (strs[j][i] != strs[0][i]) 
                    return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};