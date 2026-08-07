class Solution {
public:
    int solve(vector<vector<int>>& arr ,int i,int j,int n,int m,vector<vector<int>>& dp){
        if(i>=n || j>=m || arr[i][j] == 1) return 0;
        if(i == n-1 && j == m-1) return 1;
        if(dp[i][j] !=-1) return dp[i][j];
        return dp[i][j] = solve(arr,i+1,j,n,m,dp) + solve(arr,i,j+1,n,m,dp);


    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<vector<int>> dp(n,vector<int>(m,-1));

        return solve(obstacleGrid,0,0,n,m,dp);
        
    }
};