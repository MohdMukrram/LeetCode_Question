class Solution {
public:
    int find(int x , vector<int>& par){
        return par[x] = (par[x] == x) ? x : find(par[x],par);
    }
    void Union(int u,int v,vector<int>& rank , vector<int>& par){
        u = find(u,par);
        v = find(v,par);
        if(u == v) return;

        if(rank[u] > rank[v]) par[v] = u;
        else if(rank[v]>rank[v]) par[u] = v;
        else{
            par[v] = u;
            rank[u]++;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> rank(n,1);
        vector<int> par(n);
        for(int i=0;i<n;i++) par[i] = i;

        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0] == stones[j][0]  || stones[i][1] == stones[j][1]){
                    Union(i,j,rank,par);
                }
            }
        }

        int groups = 0;

        for(int i=0;i<n;i++){
            if(par[i] == i) groups++;
        }
        return n-groups;
    }
};