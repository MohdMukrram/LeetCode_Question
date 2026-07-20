class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int sum = 0, ans = 0;
        for(auto x : nums){
            sum += x;

            int rem = ((sum % k) + k) % k;

            ans += mp[rem];
            mp[rem]++;
        }
        return ans;
    }
};