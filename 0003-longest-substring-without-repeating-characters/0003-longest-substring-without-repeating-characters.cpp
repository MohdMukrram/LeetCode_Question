class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i=0,j=0;
        unordered_set<char> st;
        int mx = 0;

        while(j<n){
            while(st.count(s[j])){
                st.erase(s[i]);
                i++;
            }
            st.insert(s[j]);
            mx = max(mx,j-i+1);
            j++;
        }
        return mx;
    }
};