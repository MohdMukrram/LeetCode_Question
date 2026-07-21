class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto x : nums) mp[x]++;

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;

        for(auto it : mp){
            if(pq.size() < k){
                pq.push({it.second , it.first});
            }
            else{
                pq.push({it.second , it.first});
                pq.pop();
            }
        }
        vector<int> ans;

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};