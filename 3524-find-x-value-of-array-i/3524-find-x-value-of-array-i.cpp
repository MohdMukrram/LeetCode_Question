class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for(int num : nums) {
            vector<long long> next(k, 0);

            // Purane subarrays ko current number ke saath extend karo
            for(int r = 0; r < k; r++) {
                int newR = (r * (num % k)) % k;
                next[newR] += dp[r];
            }

            // Current number se naya subarray
            next[num % k]++;

            dp = next;

            // Current position par end hone wale
            // saare subarrays ko answer mein add karo
            for(int r = 0; r < k; r++) {
                ans[r] += dp[r];
            }
        }

        return ans;
    }
};