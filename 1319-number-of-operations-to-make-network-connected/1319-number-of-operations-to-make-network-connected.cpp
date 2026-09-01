class Solution {
public:
    int find(int x , vector<int>& par){
        return par[x] = (par[x] == x) ? x : find(par[x] , par);
    }
    
    bool Union(int u , int v , vector<int>& par){
        u = find(u,par);
        v = find(v,par);
        
        if(u == v) return false;
        par[v] = u;
        return true;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if(m<n-1) return -1;
        int time = n-1;
        vector<int> par(n);
        for(int i=0;i<n;i++){
            par[i] = i;
        }
        for(auto conn : connections){
            int u = conn[0] , v = conn[1];
            if(Union(u,v,par)) time--;
        }
        return time;
    }
};