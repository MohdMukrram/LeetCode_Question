class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<pair<int,int>> event;
        for(auto l : logs){
            event.push_back({l[0],1});
            event.push_back({l[1],-1});
        }

        sort(event.begin(),event.end());
        int mx = INT_MIN;
        int year = 0;
        int sum = 0;
        for(auto x : event){
            sum += x.second;
            if(mx < sum){
                year = x.first;
                mx = sum;
            }
        }
        return year;
    }
};