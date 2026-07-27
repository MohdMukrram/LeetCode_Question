class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size()) return false;

        vector<int> diff;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] != goal[i]) {
                diff.push_back(i);
            }
        }

        // Case 1: Strings are already equal
        if(diff.size() == 0) {
            unordered_set<char> st(s.begin(), s.end());
            return st.size() < s.size();
        }

        // One swap can fix exactly 2 positions
        if(diff.size() != 2) return false;

        int i = diff[0];
        int j = diff[1];

        return (s[i] == goal[j] && s[j] == goal[i]);
    }
};