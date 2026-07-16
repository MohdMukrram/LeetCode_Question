class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        int mx = 1 ;
        int i=0;
        int j = 0 , count = 1;
        while(j<n-1){
            if(nums[j] >= nums[j+1]){
                i = j+1;
                count = 1;

            }
            else count++;
            mx = max(count,mx);
            // count++;
            j++;
        }
        return mx;
    }
};