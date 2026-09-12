class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0,hi = n-1;

        if(n == 2){
            if(nums[0] == target) return true;
            if(nums[1] == target) return true;
            return false;
        }
        int pivot = -1;
        while(lo <= hi){
            int mid = lo+(hi-lo)/2;
            if(nums[mid] == target) return true;
            if(nums[lo] == nums[mid] && nums[mid] == nums[hi]){
                lo++;
                hi--;
                continue;
            }

            if(mid > 0 && nums[mid]<nums[mid-1]){
                pivot = mid;
                break;
            }
            else if(mid < n-1 && nums[mid] > nums[mid+1]){
                pivot = mid+1;
                break;
            }
            else if(nums[mid] >= nums[lo]) lo = mid + 1;
            else hi = mid - 1;
        }

        if(pivot == -1){
            lo = 0;
            hi = n-1;
        }
        else if(target >= nums[0] && target <= nums[pivot - 1]){
            lo = 0;
            hi = pivot - 1;
        }
        else{
            lo = pivot;
            hi = n-1;
        }

        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==target||nums[lo]==target||nums[hi]==target) return true;
            else if(nums[mid]>target) hi=mid-1;
            else lo=mid+1;
        }
       return false;
    }
};