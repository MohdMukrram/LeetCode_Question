class Solution {
public:
    int solve(vector<vector<int>>& arr , int i,int j, vector<vector<int>>& dp){
        int n = arr.size();
        int m = arr[0].size();
        if(j<0 || j>=m) return INT_MAX;
        if(i == n-1) return arr[i][j];
        if(dp[i][j] != INT_MAX) return dp[i][j];

        return dp[i][j] = arr[i][j] + min({solve(arr,i+1,j-1,dp) , solve(arr,i+1,j,dp),solve(arr,i+1,j+1,dp)});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,INT_MAX));
        int i = 0;
        int mn = INT_MAX;
        for(int k=0;k<m;k++){
            mn = min(mn,solve(matrix,i,k,dp));
        }

        

        return mn;
    }
};