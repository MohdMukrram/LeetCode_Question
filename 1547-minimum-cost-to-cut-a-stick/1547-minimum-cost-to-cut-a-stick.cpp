class Solution {
public:
    int solve(vector<int>& arr , int i ,int j ,vector<vector<int>>& dp){
        if(j-i < 2) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;

        for(int k=i+1;k<j;k++){
            ans = min(ans, (arr[j] - arr[i]) + solve(arr,i,k,dp) + solve(arr,k,j,dp));
        }
        return dp[i][j] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        
        int m = cuts.size();
        vector<vector<int>> dp(m+1,vector<int>(m+1,-1));

        return solve(cuts,0,m-1,dp);
    }
};