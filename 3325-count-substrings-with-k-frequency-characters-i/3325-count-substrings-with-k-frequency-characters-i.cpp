class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n = s.size();
        int i=0,j=0;
        int ans = 0;

        unordered_map<char,int> mp;
        while(j<n){
            mp[s[j]]++;
            while(mp[s[j]]>=k){
                ans += n-j;
                mp[s[i]]--;
                i++;
            }
            j++;
        }
        return ans;
    }
};