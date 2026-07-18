class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int,int>> event;

        for(auto t : trips){
            int n = t[0], u = t[1], v = t[2];
            event.push_back({u,n});
            event.push_back({v,-n});
        }
        sort(event.begin(),event.end());
        int mx = INT_MIN;
        int sum = 0;
        for(auto x : event){
            sum += x.second;
            mx = max(mx,sum);
        }

        return (mx <= capacity);
    }
};