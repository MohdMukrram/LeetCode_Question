class Solution {
public:
    int find(vector<int>& arr, int sum){
        int element = 1 , sum_element = 0;
        
        for(int i=0;i<arr.size();i++){
            if(sum_element + arr[i] <= sum){
                sum_element += arr[i];
            }
            else{
                element += 1;
                sum_element = arr[i];
            }
        }
        return element;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(k > n) return -1;

        int lo = *max_element(nums.begin(),nums.end());
        int hi = accumulate(nums.begin(),nums.end(),0);

        while(lo <= hi){
            int mid = lo + (hi-lo)/2;

            int no_element = find(nums,mid);
            if(no_element > k) lo = mid + 1;
            else hi = mid - 1;
        }
        return lo;
    }
};