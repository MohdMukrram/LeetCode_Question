class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int mx = 0;
        stack<int> st;
        for(int i=0;i<=n;i++){
            int currHeight = (i == n) ? 0 : heights[i];
            while(!st.empty() && currHeight < heights[st.top()]){
                int h = heights[st.top()];
                st.pop();
                int w = (st.empty()) ? i : i - st.top() - 1;
                mx = max(mx,h*w);
            }
            st.push(i);
        }
        return mx;
    }
};