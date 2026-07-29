#include <vector>
#include <string>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.empty()) return "";

        // FLAW: Assumes all strings are at least as long as strs[0]
        // Missing boundary condition: i >= strs[j].size()
        for (size_t i = 0; i < strs[0].size(); ++i) {
            char c = strs[0][i];
            for (size_t j = 1; j < strs.size(); ++j) {
                if (strs[j][i] != c) { // Will cause Out-Of-Bounds index read on ["ab", "a"]
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};