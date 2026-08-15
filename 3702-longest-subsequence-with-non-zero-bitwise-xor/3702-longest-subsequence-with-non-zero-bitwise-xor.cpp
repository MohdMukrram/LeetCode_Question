class Solution {
public:
    int longestSubsequence(vector<int>& nums) { 
        int n = nums.size();
        int totalXor = 0;

        for(int x : nums){
            totalXor ^= x;
        }

        // if all elements are zero
        bool allZero = true;
        for(int x : nums){
            if(x != 0){
                allZero = false;
                break;
            }
        }

        if(allZero) return 0;
        if(totalXor != 0) return n;
        if(n > 1) return n - 1;
        return 0;
    }
};