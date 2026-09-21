class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        vector<int> ngi(n);
        ngi[n-1] = n;
        stack<int> st;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }
            if(st.empty()) ngi[i] = n;
            else ngi[i] = st.top();
            st.push(i);
        }

        for(int i=0;i<n-k+1;i++){
            int mx = nums[i];
            int j = i;
            while(j<i+k){
                mx = nums[j];
                j = ngi[j];
            }
            ans.push_back(mx);
        }
        return ans;
    }
};