class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            if(grid[i][0] == 1){
                q.push({i,0});
                vis[i][0] = 1;
            }
        }

        for(int i=0;i<n;i++){
            if(grid[i][m-1] == 1){
                q.push({i,m-1});
                vis[i][m-1] = 1;
            }
        }

        for(int i=0;i<m;i++){
            if(grid[0][i] == 1){
                q.push({0,i});
                vis[0][i] = 1;
            }
        }

        for(int i=0;i<m;i++){
            if(grid[n-1][i] == 1){
                q.push({n-1,i});
                vis[n-1][i] = 1;
            }
        }

        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int d=0;d<4;d++){
                int nr = r + dir[d][0];
                int nc = c + dir[d][1];

                if(nr >=0 && nr < n && nc >=0 && nc < m && grid[nr][nc] == 1 && vis[nr][nc] != 1){
                    q.push({nr,nc});
                    vis[nr][nc] = 1;
                }
            }
        }

        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] == 0 && grid[i][j] == 1) count ++; 
            }
        }
        return count;
    }
};