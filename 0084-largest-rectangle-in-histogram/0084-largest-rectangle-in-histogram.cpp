            // approch 1
// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();
//         int mx = 0;
//         stack<int> st;
//         for(int i=0;i<=n;i++){
//             int currHeight = (i == n) ? 0 : heights[i];
//             while(!st.empty() && currHeight < heights[st.top()]){
//                 int h = heights[st.top()];
//                 st.pop();
//                 int w = (st.empty()) ? i : i - st.top() - 1;
//                 mx = max(mx,h*w);
//             }
//             st.push(i);
//         }
//         return mx;
//     }
// };
                                        // approch 2

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> nse(n);
        vector<int> pse(n);

        stack<int> st;

        // Previous Smaller Element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if (st.empty()) {
                pse[i] = -1;
            } else {
                pse[i] = st.top();
            }

            st.push(i);
        }

        // Clear stack
        while (!st.empty()) {
            st.pop();
        }

        // Next Smaller Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if (st.empty()) {
                nse[i] = n;
            } else {
                nse[i] = st.top();
            }

            st.push(i);
        }

        // Calculate maximum area
        int mx = 0;

        for (int i = 0; i < n; i++) {
            int width = nse[i] - pse[i] - 1;
            int area = heights[i] * width;

            mx = max(mx, area);
        }

        return mx;
    }
};
