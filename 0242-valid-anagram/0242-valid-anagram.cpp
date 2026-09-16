class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        for(auto x : s) mp1[x]++;
        for(auto x : t) mp2[x]++;
        if(mp1.size()!=mp2.size()) return false;
        for(auto x : mp1){
            if(x.second != mp2[x.first]) return false;
        }
        return true;
    }
};