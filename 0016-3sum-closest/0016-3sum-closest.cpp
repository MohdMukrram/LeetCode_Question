class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        if(n<3) return 0;
        sort(nums.begin(),nums.end());
        int sum=nums[0]+nums[1]+nums[2];
        for(int i=0;i<n;i++){
            int lo=i+1;
            int hi=n-1;
            while(lo<hi){
                int currentSum = nums[i] + nums[lo] + nums[hi];
                if(currentSum==target) return currentSum;
                if(abs(currentSum-target) < abs(sum-target)){
                    sum=currentSum;
                }
                else if(currentSum<target) lo++;
                else hi--;
            }
        }
        return sum;
    }
};