class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        if(n==1) return s;
        unordered_map<char,int> mp;
        for(auto x : s){
            mp[x]++;

            if(mp[x] > ceil(n/2.0)) return "";
        }

        priority_queue<pair<int,char>> pq;

        for(auto x : mp){
        if(x.second > ceil(n/2.0)) return "";
            pq.push({x.second,x.first});

        }

        if(pq.size() == 1 && pq.top().first > 1){
            return "";
        }
        
        string ans="";
        while(pq.size() > 1){
            auto a = pq.top();
            pq.pop();
            auto b = pq.top();
            pq.pop();
            ans += a.second;
            ans += b.second;

            if(a.first - 1 > 0) pq.push({a.first-1,a.second});
            if(b.first - 1 > 0) pq.push({b.first-1,b.second});
        }
        if(!pq.empty()){
            ans += pq.top().second;
        }
        return ans;
    }
};