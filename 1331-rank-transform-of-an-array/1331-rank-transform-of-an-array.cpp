class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp = arr;

        sort(temp.begin(),temp.end());

        unordered_map<int,int> mp;
        unordered_set<int> st(temp.begin(),temp.end());
        int c = 1;
        for(auto x : temp) {
            if(!mp.count(x)){
                mp[x] = c++;
            }
        }

        vector<int> ans;

        for(auto x : arr){
            if(mp.count(x)){
                ans.push_back(mp[x]);
            }
        }

        return ans;
    }
};