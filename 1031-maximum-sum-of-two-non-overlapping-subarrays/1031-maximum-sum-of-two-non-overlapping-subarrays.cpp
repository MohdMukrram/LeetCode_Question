class Solution {
public:
    int solve(vector<int>& nums, int len1, int len2,vector<int>& prefix) {

        int n = nums.size();

        int maxFirst = 0;
        int ans = 0;

        for (int i = len1; i + len2 <= n; i++) {

            // Best len1 subarray before current len2
            int firstSum = prefix[i] - prefix[i - len1];

            maxFirst = max(maxFirst, firstSum);

            // Current len2 subarray
            int secondSum = prefix[i + len2] - prefix[i];

            ans = max(ans, maxFirst + secondSum);
        }

        return ans;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        // firstLen subarray comes before secondLen
        int ans1 = solve(nums, firstLen, secondLen, prefix);

        // secondLen subarray comes before firstLen
        int ans2 = solve(nums, secondLen, firstLen, prefix);

        return max(ans1, ans2);
    }
    
};