class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;
        for(int i=n-1;i>0;i--){
            if(nums[i-1] < nums[i]){
                idx = i-1;
                break;
            }
        }
        

        if(idx != -1){
            int gr = -1;
            for(int i=n-1;i>=idx+1;i--){
                if(nums[i] > nums[idx]){
                    gr = i;
                    break;
                }
            }
            swap(nums[idx],nums[gr]);
        }
        reverse(nums.begin()+idx+1 , nums.end());

    }
};