class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        vector<int> events(n + 1, 0);
        for (auto r : requests) {
            events[r[0]]++;
            events[r[1] + 1]--;
        }
        for (int i = 1; i < n; i++) {
            events[i] += events[i - 1];
        }
        sort(nums.rbegin(), nums.rend());
        sort(events.rbegin(), events.rend());

        long long ans = 0;
        const int MOD = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            ans = (ans + 1LL * nums[i] * events[i]) % MOD;
        }

        return ans;
    }
};