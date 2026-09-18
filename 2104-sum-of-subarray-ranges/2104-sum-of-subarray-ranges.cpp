class Solution {
public:
    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;

        vector<int> left(n), right(n);
        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }

            left[i] = st.empty() ? i+1 : i - st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }

            right[i] = st.empty() ? n-i : st.top() - i;
            st.push(i);
        }

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum = (sum + 1LL * arr[i] * left[i] * right[i]);
        }

        return sum;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;

        vector<int> left(n), right(n);
        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] < arr[i]){
                st.pop();
            }

            left[i] = st.empty() ? i+1 : i - st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] <= arr[i]){
                st.pop();
            }

            right[i] = st.empty() ? n-i : st.top() - i;
            st.push(i);
        }

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum = (sum + 1LL * arr[i] * left[i] * right[i]);
        }

        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        long long ans =  (sumSubarrayMaxs(nums) - sumSubarrayMins(nums));
        //if(ans < 0) ans += MOD;
        return ans;
    }
};