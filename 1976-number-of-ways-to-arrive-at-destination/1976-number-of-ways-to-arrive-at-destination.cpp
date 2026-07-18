class Solution {
public:
    int mod = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto r : roads){
            int u = r[0] , v = r[1] , w = r[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        priority_queue<pair<long long,int> , vector<pair<long long,int>> , greater<pair<long long,int>>> pq;
        vector<long long> dist(n,LLONG_MAX);
        vector<int> way(n);
        pq.push({0,0});
        dist[0] = 0;
        way[0] = 1;

        while(!pq.empty()){
            auto [d,u] = pq.top();
            pq.pop();

            if(d > dist[u]) continue;

            for(auto [v,w] : adj[u]){
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v],v});
                    way[v] = way[u];
                }
                else if(dist[v] == dist[u] + w){
                    way[v] = (way[u] + way[v]) % mod;
                }
            }
        }
        return way[n-1];
    }
};