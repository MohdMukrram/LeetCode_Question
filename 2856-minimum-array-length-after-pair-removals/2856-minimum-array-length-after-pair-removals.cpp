class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        int j=(n+1)/2;
        int pairs = 0;
        while(j<n){
            if(nums[i]<nums[j]){
                pairs++;
                i++;
                j++;
            }
            else j++;
        }
        return n - 2*pairs;
    }
};