class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1) q.push({i,j});
            }
        }
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        int ans = 0;
        while(!q.empty()){
            int r = q.front().first;
            int c  = q.front().second;
            q.pop();

            int count = 0;
            for(int d=0;d<4;d++){
                int nr = r + dir[d][0];
                int nc = c + dir[d][1];

                if(nr >= 0 && nr < n && nc >=0 && nc < m && grid[nr][nc] == 1){
                    count++;
                    
                }
            }
            ans += 4-count;
            
        }
        return ans;
    }
};