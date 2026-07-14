class Solution {
public:
    bool solve(vector<vector<int>>& adj , int node, int newColor,vector<int>& color){
        color[node] = newColor;

        for(auto x : adj[node]){
            if(color[x] == color[node]) return false;
            if (color[x] == -1) {
                if (!solve(adj, x, !newColor, color)) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);

        for(int i=0;i<n;i++){
            if(color[i] == -1){
                if(!solve(graph,i,0,color)){
                    return false;
                }
            }
        }
        return true;
    }
};