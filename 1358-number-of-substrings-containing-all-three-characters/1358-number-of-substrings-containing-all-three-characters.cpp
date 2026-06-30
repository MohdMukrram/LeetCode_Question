class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int mx = 0;
        int i=0 , j=0;

        vector<int> mp(3,0);

        while(j<n){
            mp[s[j]-'a']++;
            while(mp[0] > 0 && mp[1] > 0 && mp[2] > 0){
                mx += (n-j);
                mp[s[i] - 'a']--;
                i++;
            }
            j++;
        }
        return mx;
    }
};