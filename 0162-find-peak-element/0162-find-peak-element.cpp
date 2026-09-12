class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if (n == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[n - 1] > nums[n - 2]) return n - 1;
        
        int lo = 1;
        int hi = n-2;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;

            if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]) return mid;
            else if(nums[mid-1] < nums[mid]) lo = mid + 1;
            else hi = mid - 1;
        }
        return -1;
    }
};