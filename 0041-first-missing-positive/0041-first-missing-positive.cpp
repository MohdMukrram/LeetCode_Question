class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st(nums.begin(),nums.end());

        for(int i=1;i<=n;i++){
            if(!st.count(i)) return i;
        }
        return n+1;
    }
};