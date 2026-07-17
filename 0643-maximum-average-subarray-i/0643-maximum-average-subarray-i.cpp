class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();

        int i=0,j=0;
        double mx = INT_MIN;
        long long sum = 0;
        while(j<n){
            while(j-i+1 > k){
                sum -= nums[i];
                i++;
            }
            sum += nums[j];
            if (j - i + 1 == k) {
                mx = max(mx, (double)sum / k);
            }
            j++;
        }
        return mx;
    }
};