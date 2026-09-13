class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ans(n+m);

        int i=0 , j=0 , k=0;

        while(i<n && j<m){
            if(nums1[i] < nums2[j]){
                ans[k++] = nums1[i];
                i++;
            }
            else{
                ans[k++] = nums2[j];
                j++;
            }
        }

        while(i<n){
            ans[k++] = nums1[i];
            i++;
        }

        while(j<m){
            ans[k++] = nums2[j];
            j++;
        }
        int s = n+m;
        if(s%2==0) return (ans[s/2] + ans[(s/2)-1])/2.0;
        return ans[s/2];
    }
};