class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        stack<string> st;
        string ans = "";

        for(int i = 0; i < n; i++) {
            if(s[i] != ' ') {
                ans += s[i];
            }
            else {
                if(ans != "") {
                    st.push(ans);
                    ans = "";
                }
            }
        }

        if(ans != "") st.push(ans);

        string res = "";

        while(!st.empty()) {
            res += st.top();
            st.pop();

            if(!st.empty()) res += " ";
        }

        return res;
    }
};