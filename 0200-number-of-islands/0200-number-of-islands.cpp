class Solution {
public:
    void solve(vector<vector<char>>& arr , int i , int j , vector<vector<int>>& vis){
        if(i < 0 || i>=arr.size() || j < 0 || j>=arr[0].size() || vis[i][j] == 1 || arr[i][j] != '1') return;
        vis[i][j] = 1;

        solve(arr,i,j+1,vis);
        solve(arr,i,j-1,vis);
        solve(arr,i+1,j,vis);
        solve(arr,i-1,j,vis);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && vis[i][j] != 1){
                    count ++;
                    solve(grid,i,j,vis);
                }
            }
        }
        return count;
    }
};