class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);

        for(auto x : invocations){
            int u = x[0];
            int v = x[1];

            adj[u].push_back(v);
        }

        vector<bool> vis(n,false);
        queue<int> q;
        q.push(k);
        vis[k] = true;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto neighbour : adj[node]){
                if(!vis[neighbour]){
                    q.push(neighbour);
                    vis[neighbour] = true;
                }
            }
        }

        for(auto e : invocations){
            int u = e[0] , v = e[1];
            if(!vis[u] && vis[v]){
                vector<int> ans;
                for(int i=0;i<n;i++){
                    ans.push_back(i);
                }
                return ans;
            }
        }

        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!vis[i]) ans.push_back(i);
        }

        return ans;
    }
};