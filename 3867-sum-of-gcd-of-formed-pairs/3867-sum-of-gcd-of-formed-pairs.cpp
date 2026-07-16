class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        int mx = 0;
        vector<int> ans;
        for(int i=0;i<n;i++){
            mx = max(nums[i],mx);
            ans.push_back(__gcd(nums[i],mx));
        }

        sort(ans.begin(),ans.end());
        
        int i=0,j=n-1;
        long long sum = 0;
        while(i<j){
            sum += __gcd(ans[i],ans[j]);
            i++;
            j--;
        }
        return sum;
    }
};