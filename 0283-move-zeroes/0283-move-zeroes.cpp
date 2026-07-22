class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;

        for (int j = 1; j < nums.size(); j++) {
            if (nums[i] != nums[j] && nums[i] == 0) {
                swap(nums[i],nums[j]);
            }
            if(nums[i] != 0) i++;
        }

        
    }
};