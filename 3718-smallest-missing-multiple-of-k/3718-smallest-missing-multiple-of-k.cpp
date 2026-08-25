class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = *max_element(nums.begin(),nums.end());
        unordered_set<int> st(nums.begin(),nums.end());
        int ans = 0;
        for(int i=1;i<=mx;i++){
            if(!st.count(k*i)){
                return k*i;
            }
        }
        return mx+1;
    }
};