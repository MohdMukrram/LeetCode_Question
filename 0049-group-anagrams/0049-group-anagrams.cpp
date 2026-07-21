class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& arr) {
        vector<vector<string>> ans; 
        unordered_map<string , vector<string>> m;
        for(string str : arr){
            string lexo = str;
            sort(lexo.begin(),lexo.end());
            if(m.find(lexo)==m.end()){
                vector<string> v;
                v.push_back(str);
                m[lexo] = v;
            }
            else{
                m[lexo].push_back(str);
            }
        }
        for(auto x : m){
            vector<string> v = x.second;
            ans.push_back(v);
        }
        return ans;
    }
};