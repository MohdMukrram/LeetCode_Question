class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        for(int i=0;i<p.size();i++){
            adj[p[i][1]].push_back(p[i][0]);
                indegree[p[i][0]]++;    
        }
        queue<int> q;
        queue<int> topo;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
            while(!q.empty()){
                int n=q.front();
                q.pop();
                topo.push(n);
                for(auto it:adj[n]){
                    indegree[it]--;
                    if(indegree[it]==0){
                        q.push(it);
                    }
                }
            }
            if(topo.size()==numCourses){
                return true;
            }
            return false;
    }
};