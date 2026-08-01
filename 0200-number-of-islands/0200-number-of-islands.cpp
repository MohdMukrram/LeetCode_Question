class Solution {
public:
    void solve(vector<vector<char>>& grid,int i,int j,vector<vector<int>>& vis){
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};

        q.push({i,j});
        vis[i][j] = 1;

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int d=0;d<4;d++){
                int nr = r + dir[d][0];
                int nc = c + dir[d][1];

                if(nr >=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] == '1' && !vis[nr][nc]){
                    q.push({nr,nc});
                    vis[nr][nc] = 1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    count++;
                    solve(grid,i,j,vis);
                }
            }
        }

        return count;
    }
};