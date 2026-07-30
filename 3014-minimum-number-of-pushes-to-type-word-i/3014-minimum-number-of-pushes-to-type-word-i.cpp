class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();

        int ans = 0;

        for (int i = 0; i < n; i++) {
            // Every 8 letters move to the next push level
            int pushes = (i / 8) + 1;
            ans += pushes;
        }

        return ans;
    }
};