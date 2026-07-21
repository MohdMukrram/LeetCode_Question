class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i=0,j=0;
        int k = 1;
        int mx = INT_MIN;

        while(j<n){
            if(nums[j] == 0) k--;
            while(k<0){
                if(nums[i] == 0) k++;
                i++;
            }
            mx = max(mx,j-i);
            j++;
        }
        return mx;
    }
};