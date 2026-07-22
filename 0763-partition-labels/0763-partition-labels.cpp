class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();

        unordered_map<char, int> mp;

        // Store last occurrence
        for (int i = 0; i < n; i++) {
            mp[s[i]] = i;
        }

        vector<int> ans;

        int start = 0;
        int end = 0;

        for (int i = 0; i < n; i++) {

            // Expand partition to last occurrence
            // of current character
            end = max(end, mp[s[i]]);

            // We can make a partition
            if (i == end) {
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return ans;
    }
};