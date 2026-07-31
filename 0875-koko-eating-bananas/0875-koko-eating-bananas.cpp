class Solution {
public:
    bool check(vector<int>& arr , int mid , int h){
        int n = arr.size();
        long long ans = 0;

        for(int i=0;i<n;i++){
            ans += ceil(arr[i]/(double)mid);
            if(ans > h) return false;
        }

        return ans <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = *max_element(piles.begin(),piles.end());

        int ans = 0;

        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(check(piles,mid,h)){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }
};