class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v(nums1.size() , -1);
        stack<int> st;

        for(int i=0;i<nums2.size();i++){
            while(st.size() > 0 && st.top() < nums2[i]){
                int x = st.top();
                st.pop();

                for(int j=0;j<nums1.size();j++){
                    if(nums1[j] == x){
                        v[j] = nums2[i];
                    }
                }
            }
            st.push(nums2[i]);
        }
        return v;
    }
};