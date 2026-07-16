class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(auto x : nums) mp[x]++;

        int mx = 0;
        for(auto x : mp)
            mx = max(mx, x.second);

        int ans = nums.size();

        for(auto x : mp){
            if(x.second == mx){
                int f = -1, l = -1;
                for(int i = 0; i < nums.size(); i++){
                    if(nums[i] == x.first){
                        if(f == -1) f = i;
                        l = i;
                    }
                }
                ans = min(ans, l - f + 1);
            }
        }

        return ans;
    }
};