class Solution {
public:
    bool check(vector<int>& arr , int day , int mid){
        int ans = 0;
        int count = 1;
        for(auto x : arr){
            
            if(ans + x > mid){
                ans = 0;
                count++;
            }
            ans += x;
        }
        return count <= day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = *max_element(weights.begin(), weights.end());
        int hi = accumulate(weights.begin(),weights.end(),0);

        int ans = 0;

        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(check(weights,days,mid)){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }
};