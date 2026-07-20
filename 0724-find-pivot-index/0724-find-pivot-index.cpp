class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int>pref(n,0);
        pref[0] = nums[0];

        for(int i=1;i<n;i++){
            pref[i] = pref[i-1] + nums[i];
        }

        for(int i=0;i<n;i++){
            if(i==0){
                if(pref[n-1]-pref[0] == 0) return 0;
            }
            else if(i==n-1){
                if(pref[n-2] == 0) return n-1;
            }
            else if(i>0 && i<n-1){
                if(pref[i-1] == (pref[n-1] - pref[i])) return i;
            }
        }
        return -1;
    }
};