class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;
        queue<tuple<int,int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dir = {{0,-1},{0,1},{-1,0},{1,0},{-1,1},{1,-1},{-1,-1},{1,1}};
        q.push({0,0,1});
        vis[0][0] = 1;

        while(!q.empty()){
            auto [r,c,d] = q.front();
            q.pop();

            if(r == n-1 && c == m-1) return d;
            for(int i=0;i<8;i++){
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];

                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] == 0 && !vis[nr][nc]){
                    q.push({nr,nc,d+1});
                    vis[nr][nc] = 1;
                }
            }
        }
        return -1;
    }
};