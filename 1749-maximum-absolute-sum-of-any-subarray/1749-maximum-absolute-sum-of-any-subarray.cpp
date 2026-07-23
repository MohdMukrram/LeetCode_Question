class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int mx=0,mn=0;
        int sum = 0;

        for(int i=0;i<n;i++){
            sum += nums[i];
            mx = max(mx,sum);
            mn = min(mn,sum);
        }
        return abs(mx-mn);
    }
};