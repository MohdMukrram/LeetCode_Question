class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int lo = 0;
        int hi = n - 1;

        while(lo<=hi){
            int mid = lo + (hi - lo)/2;

            if(nums[mid] == nums[lo] && nums[mid] == nums[hi]){
                lo++;
                hi--;
            }

            else if(mid > 0 && nums[mid] < nums[mid - 1]){
                return nums[mid];
            }

            else if(mid < n-1 && nums[mid] > nums[mid + 1]){
                return nums[mid + 1];
            }
            else if(nums[mid] >= nums[lo]) lo = mid + 1;
            else hi = mid - 1;
            
        }
        return nums[0];
    }
};