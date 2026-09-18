class Solution {
public:
    vector<int> getNSL(vector<int>& arr, int n){
        stack<int> st;
        vector<int> res(n);

        for(int i=0;i<n;i++){
            if(st.empty()){
                res[i] = -1;
            }
            else{
                while(!st.empty() && arr[st.top()] >= arr[i]){
                    st.pop();
                }
                res[i] = (st.empty())?-1:st.top();
            }
            st.push(i);
        }
        return res;
    }
    vector<int> getNSR(vector<int>& arr, int n){
        stack<int> st;
        vector<int> res(n);

        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                res[i] = n;
            }
            else{
                while(!st.empty() && arr[st.top()] > arr[i]){
                    st.pop();
                }
                res[i] = (st.empty()) ? n:st.top();
            }
            st.push(i);
        }
        return res;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> NSL = getNSL(arr,n);
        vector<int> NSR = getNSR(arr,n);

        long long sum = 0;
        int M = 1e9 + 7;

        for(int i=0;i<n;i++){
            long long l = i - NSL[i];
            long long R = NSR[i] - i;

            long long totalways = l*R;
            long long totalsum = totalways*arr[i];
            sum = (sum + totalsum)%M;
        }
        return sum;
    }
};