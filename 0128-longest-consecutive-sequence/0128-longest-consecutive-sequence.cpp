class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        unordered_set<int> st;

        for(auto x : nums) st.insert(x);

        int mx = 1;
        for(auto it : st){
            if(!st.count(it-1)){
                int count = 1;
                int x = it;

                while(st.count(x+1)){
                    x++;
                    count++;
                }
                mx = max(mx,count);
            }
        }
        return mx;
    }
};