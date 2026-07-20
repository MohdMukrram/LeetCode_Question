class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[0] = -1;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem = sum % k;
            // if(rem < 0) rem += k;
            if(mp.count(rem)) {
                if(i - mp[rem] >= 2) return true;
            } 
            else {
                // Store only the first occurrence
                mp[rem] = i;
            }
        }
        return false;
    }
};