class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        for(auto pre : prerequisites){
            adj[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0) q.push(i);
        }
        int count = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            for(auto neighbour : adj[node]){
                indegree[neighbour]--;
                if(indegree[neighbour] == 0) q.push(neighbour);
            }
        }
        return (count == numCourses);
    }
};