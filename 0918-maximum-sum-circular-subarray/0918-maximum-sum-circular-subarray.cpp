class Solution {
public:
    int mnSum(vector<int>& nums){
        int n = nums.size();
        int sum = nums[0];
        int mn = nums[0];

        for(int i=1;i<n;i++){
            sum = min(sum+nums[i] , nums[i]);
            mn = min(mn,sum);
        }
        return mn;
    }
    int mxSum(vector<int>& nums){
        int n = nums.size();
        int sum = nums[0];
        int mx = nums[0];

        for(int i=1;i<n;i++){
            sum = max(sum+nums[i] , nums[i]);
            mx = max(mx,sum);
        }
        return mx;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(auto x : nums) total += x;
        int val1 = mxSum(nums);
        int val2 = mnSum(nums);

        return (val1 > 0) ? max(val1 , (total - val2)) : val1;
    }
};