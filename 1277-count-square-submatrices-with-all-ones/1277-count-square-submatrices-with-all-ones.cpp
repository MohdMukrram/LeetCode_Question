class Solution {
public:
    int n,m;
    int solve(vector<vector<int>>& mat , int i,int j,vector<vector<int>>& dp){
        if(i>=n || j>=m || mat[i][j] == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int r = solve(mat,i,j+1,dp);
        int b = solve(mat,i+1,j,dp);
        int d = solve(mat,i+1,j+1,dp);

        return dp[i][j] = 1 + min({r,b,d});

    }
    int countSquares(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 1){
                    ans += solve(matrix,i,j,dp);
                }
            }
        }
        return ans;
    }
};