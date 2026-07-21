class Solution {
public:
    int first(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0;
        int hi = n-1;
        int idx = -1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(nums[mid] == target){
                idx = mid;
                hi = mid-1;
            }
            else if(nums[mid] > target) hi = mid-1;
            else lo = mid+1;
        }
        return idx;
    }
    int last(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0;
        int hi = n-1;
        int idx = -1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(nums[mid] == target){
                idx = mid;
                lo = mid+1;
            }
            else if(nums[mid] < target) lo = mid+1;
            else hi = mid-1;
        }
        return idx;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int f = first(nums,target);
        int l = last(nums,target);
        return {f,l};
    }
};