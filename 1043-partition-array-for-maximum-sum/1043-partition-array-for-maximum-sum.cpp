class Solution {
public:
    int solve(vector<int>& arr, int i,int k,vector<int>& dp){
        if(i>=arr.size()) return 0;
        if(dp[i] != -1) return dp[i];

        int res = 0;
        int mx = -1;
        for(int j=i;j<arr.size() && j-i+1<=k;j++){
            mx = max(mx,arr[j]);

            res = max(res,(mx*(j-i+1)) + solve(arr,j+1,k,dp));
        }
        return dp[i] = res;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n,-1);

        return solve(arr,0,k,dp);
    }
};