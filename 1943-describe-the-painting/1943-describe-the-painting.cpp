class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<int,long long> events;

        for(auto s : segments){
            events[s[0]] += s[2];
            events[s[1]] -= s[2];
        }

        vector<vector<long long>> ans;
        auto it = events.begin();

        long long sum = it->second;
        int start = it->first;
        it++;

        while(it != events.end()){
            if(sum > 0){
                ans.push_back({start,it->first,sum});
            }
            sum += it->second;
            start = it->first;
            it++;
        }
        
        return ans;
    }
};