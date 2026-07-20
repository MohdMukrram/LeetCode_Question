class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int i=0;
        int j=0;
        int count = 0;
        int mx = INT_MIN;
        unordered_set<char> st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');

        while(j<n){
            while(j-i+1 > k){
                if(st.count(s[i])){
                    count--;
                }
                i++;
            }
            if(st.count(s[j])) count++;
            mx = max(mx,count);
            j++;
        }
        return mx;
    }
};