class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            if(board[i][0] == 'O'){
                q.push({i,0});
                vis[i][0] = 1;
            }
        }

        for(int i=0;i<n;i++){
            if(board[i][m-1] == 'O'){
                q.push({i,m-1});
                vis[i][m-1] = 1;
            }
        }

        for(int i=0;i<m;i++){
            if(board[0][i] == 'O'){
                q.push({0,i});
                vis[0][i] = 1;
            }
        }

        for(int i=0;i<m;i++){
            if(board[n-1][i] == 'O'){
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

                if(nr >=0 && nr < n && nc >=0 && nc < m && board[nr][nc] == 'O' && vis[nr][nc] != 1){
                    q.push({nr,nc});
                    vis[nr][nc] = 1;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] == 0 && board[i][j] == 'O') board[i][j] = 'X'; 
            }
        }
    }
};