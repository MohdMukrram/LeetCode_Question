class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIdx = 0;
        int maxIdx = 0;

        // Find indices of minimum and maximum
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minIdx])
                minIdx = i;

            if (nums[i] > nums[maxIdx])
                maxIdx = i;
        }

        int left = min(minIdx, maxIdx);
        int right = max(minIdx, maxIdx);

        // Three possible ways
        int fromFront = right + 1;
        int fromBack = n - left;
        int bothEnds = (left + 1) + (n - right);

        return min({fromFront, fromBack, bothEnds});
    }
};