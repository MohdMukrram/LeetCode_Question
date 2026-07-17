class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> effect(n,vector<int>(m,INT_MAX));
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        priority_queue<tuple<int,int,int> , vector<tuple<int,int,int>> , greater<>> pq;

        pq.push({0,0,0});
        effect[0][0] = 0;

        while(!pq.empty()){
            auto [curreff,r,c] = pq.top();
            pq.pop();

            if(r==n-1 && c==m-1) return curreff;
            for(int i=0;i<4;i++){
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];

                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int diff = abs(heights[nr][nc] - heights[r][c]);
                    int maxEff = max(curreff,diff);
                    if(maxEff < effect[nr][nc]){
                        effect[nr][nc] = maxEff;
                        pq.push({effect[nr][nc],nr,nc});
                    }
                }
            }
        }
        return -1;
    }
};