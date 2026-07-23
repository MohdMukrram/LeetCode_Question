class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int suf = 1;
        int pre = 1;
        int mx = INT_MIN;
        for(int i=0;i<n;i++){
            if(pre == 0) pre = 1;
            if(suf == 0) suf = 1;
            pre *= nums[i];
            suf *= nums[n-i-1];
            mx = max({mx,pre,suf});
        }
        return mx;
    }
};