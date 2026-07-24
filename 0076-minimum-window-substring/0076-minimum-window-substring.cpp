class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        unordered_map<char,int> mp;
        for(auto x : t) mp[x]++;
        
        int i=0, j=0, idx=-1, cnt = 0, mn=INT_MAX;

        while(j<n){
            if(mp[s[j]] > 0) cnt++;
            mp[s[j]]--;

            while(cnt == t.size()){
                if(j-i+1 < mn){
                    mn = j-i+1;
                    idx = i;
                }
                mp[s[i]]++;
                if(mp[s[i]] > 0) cnt--;
                i++;
            }
            j++;
        }

        return (idx != -1) ? s.substr(idx,mn) : "";
    }
};