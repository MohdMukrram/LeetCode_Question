class Solution {
public:
    void dfs(vector<vector<int>>& adj,int node, unordered_set<int>& vis){
        vis.insert(node);

        for(auto neighbour : adj[node]){
            if(!vis.count(neighbour)){
                dfs(adj,neighbour,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;

        vector<vector<int>> adj(n);

        // build adjacency list
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                }
            }
        }

        unordered_set<int> vis;

        for(int i=0;i<n;i++){
            if(!vis.count(i)){
                dfs(adj,i,vis);
                count++;
            }
        }
        return count;
    }
};