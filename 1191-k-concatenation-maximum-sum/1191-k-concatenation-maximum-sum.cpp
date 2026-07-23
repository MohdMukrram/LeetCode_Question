class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        const long long MOD = 1e9 + 7;
        int n = arr.size();

        // Case 1: Only one copy
        if (k == 1) {
            long long sum = 0;
            long long mx = 0;

            for (int x : arr) {
                sum = max(0LL, sum + x);
                mx = max(mx, sum);
            }

            return mx;
        }

        // Calculate total sum
        long long total = 0;
        for (int x : arr) {
            total += x;
        }

        // Case 2: k >= 2
        // Kadane on 2 copies
        long long sum = 0;
        long long mx = 0;

        for (int i = 0; i < 2 * n; i++) {
            sum = max(0LL, sum + arr[i % n]);
            mx = max(mx, sum);
        }

        // If total is positive, add middle copies
        if (total > 0) {
            mx += (long long)(k - 2) * total;
        }

        return mx % MOD;
    }
};