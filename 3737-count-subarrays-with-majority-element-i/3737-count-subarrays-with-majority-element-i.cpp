class Solution {
public:
    int countMajoritySubarrays(std::vector<int>& nums, int target) {
        int n = nums.size();
        int totalValid = 0;

        // Start index of the subarray
        for (int i = 0; i < n; ++i) {
            int balance = 0;
            
            // End index of the subarray
            for (int j = i; j < n; ++j) {
                // If the element matches target, it contributes +1
                // Otherwise, it contributes -1
                if (nums[j] == target) {
                    balance++;
                } else {
                    balance--;
                }

                // If balance > 0, target appears more than 50% of the time
                if (balance > 0) {
                    totalValid++;
                }
            }
        }
        
        return totalValid;
    }

};