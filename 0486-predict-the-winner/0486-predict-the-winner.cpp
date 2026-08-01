class Solution {
public:
    int solve(int i, int j, vector<int>& nums) {
        if (i == j)
            return nums[i];

        int takeLeft  = nums[i] - solve(i + 1, j, nums);
        int takeRight = nums[j] - solve(i, j - 1, nums);

        return max(takeLeft, takeRight);
    }

    bool predictTheWinner(vector<int>& nums) {
        return solve(0, nums.size() - 1, nums) >= 0;
    }
};