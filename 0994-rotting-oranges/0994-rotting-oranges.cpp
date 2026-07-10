class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        int f = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if(grid[i][j] == 1) f++;
            }
        }
        vector<vector<int>> dir = {{0,1},{0,-1},{-1,0},{1,0}};
        q.push({-1,-1});
        int mins = 0;
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            if(r == -1 && c == -1){
                if(q.empty()){
                    mins++;
                    break;
                }
                else if(!q.empty()){
                    mins++;
                    q.push({-1,-1});
                }
            }
            
            for(int d=0;d<4;d++){
                int nr = r + dir[d][0];
                int nc = c + dir[d][1];

                if(nr>=0 && nr <n && nc>=0 && nc<m && grid[nr][nc] == 1){
                    grid[nr][nc] = 2;
                    q.push({nr,nc});
                    f--;
                }
            }
            
        }
        return (f!=0) ? -1 : mins-1;
    }
};