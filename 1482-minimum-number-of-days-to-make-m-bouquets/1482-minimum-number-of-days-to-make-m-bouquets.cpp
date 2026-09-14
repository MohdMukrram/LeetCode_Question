class Solution {
public:
    bool can_make(vector<int>& bloomDay,int mid, int m, int k){
        int b = 0;
        int count = 0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i] <= mid){
                count++;
                if(count == k){
                    b++;
                    count = 0;
                }
            }
            else{
                count = 0;
            }
        }

        return b >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int lo = *min_element(bloomDay.begin() , bloomDay.end());
        int hi = *max_element(bloomDay.begin() , bloomDay.end());
        int ans = -1;
        if((long long)m*k > (long long)bloomDay.size()) return -1;
        while(lo <= hi){
            int mid = lo +(hi-lo)/2;

            if(can_make(bloomDay,mid,m,k)){
                ans = mid;
                hi = mid -1;
            }
            else{
                lo = mid + 1;
            }
        }
        return ans;
    }
};