class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int> st;
        string ans = "";

        for(char ch : s) {
            if(ch == '(') {
                if(!st.empty()) ans += '(';
                st.push(ch);
            }
            else {
                st.pop();
                if(!st.empty()) ans += ')';
            }
        }

        return ans;
    }
};