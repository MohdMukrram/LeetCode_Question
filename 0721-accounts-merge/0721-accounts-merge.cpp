class Solution {
public:
    int find(vector<int>& parent, int x) {
        return parent[x] = (parent[x] == x) ? x : find(parent, parent[x]);
    }

    void Union(vector<int>& parent, vector<int>& rank , int u , int v){
        u = find(parent,u);
        v = find(parent,v);
        if(u==v) return;
        if(rank[u] > rank[v]){
            parent[v] = u;
        }
        else if(rank[v] > rank[u]){
            parent[u] = v;
        }
        else{
            parent[v] = u;
            rank[u]++;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> parent(n);
        vector<int> rank(n,1);
        unordered_map<string , int> mp;
        for(int i=0;i<n;i++) parent[i] = i;

        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail = accounts[i][j];
                if(!mp.count(mail)){
                    mp[mail] = i;
                }
                else{
                    Union(parent,rank,i,mp[mail]);
                }
            }
        }

        vector<vector<string>> marge(n);
        for(auto it : mp){
            string mail = it.first;
            int node = find(parent,it.second);
            marge[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(marge[i].size() == 0) continue;
            sort(marge[i].begin(),marge[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it : marge[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};