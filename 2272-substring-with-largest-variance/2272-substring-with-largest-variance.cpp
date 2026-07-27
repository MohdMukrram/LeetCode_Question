class Solution {
public:
    int largestVariance(string s) {
        int n = s.size();
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++) mp[s[i]] = i;

        int mx = 0;
        for(int i=0;i<n;i++){
            int j = mp[s[i]];
            mx = max(mx,j-i-1);
        }
        return mx;
    }
};