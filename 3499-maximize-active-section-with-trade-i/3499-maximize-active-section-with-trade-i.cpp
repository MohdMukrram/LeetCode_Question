class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();

        // Add artificial 1 at both ends
        string t = "1" + s + "1";

        vector<pair<char, int>> groups;

        // Run-length encoding
        for (int i = 0; i < t.size(); ) {
            int j = i;

            while (j < t.size() && t[j] == t[i]) {
                j++;
            }

            groups.push_back({t[i], j - i});
            i = j;
        }

        // Count original number of 1s
        int ones = 0;

        for (char c : s) {
            if (c == '1') {
                ones++;
            }
        }

        int ans = ones;

        // Look for:
        // 0-group, 1-group, 0-group
        for (int i = 1; i + 1 < groups.size(); i++) {

            if (groups[i].first == '1' &&
                groups[i - 1].first == '0' &&
                groups[i + 1].first == '0') {

                int leftZero = groups[i - 1].second;
                int rightZero = groups[i + 1].second;

                ans = max(ans, ones + leftZero + rightZero);
            }
        }

        return ans;
    }
};