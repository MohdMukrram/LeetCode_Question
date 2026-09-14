class Solution {
public:
    bool solve(vector<int>& piles, int k , int h){
        long long hours = 0;
        for(int i=0;i<piles.size();i++){
            hours += ceil(piles[i]/(double)k);

        }
        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx = *max_element(piles.begin(),piles.end());
        int lo = 1, hi = mx;
        
        int ans = -1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(solve(piles,mid,h)){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid + 1;
        }
        return ans;
    }
};