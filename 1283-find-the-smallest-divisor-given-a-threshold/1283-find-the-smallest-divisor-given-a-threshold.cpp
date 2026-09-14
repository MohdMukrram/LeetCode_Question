class Solution {
public:
    bool solve(vector<int>& nums,int mid, int t){
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += ceil((double)nums[i]/(double)mid);
        }
        return sum <= t;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1;
        int hi = *max_element(nums.begin(),nums.end());

        int ans=-1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(solve(nums,mid,threshold)){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }
};