class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        for(int i=0;i<n;i++){
            for(auto neighbour : graph[i]){
                adj[neighbour].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        vector<int> ans;

        for(int i=0;i<n;i++){
           if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto neighbour : adj[node]){
                indegree[neighbour]--;
                if(indegree[neighbour] == 0) q.push(neighbour);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};