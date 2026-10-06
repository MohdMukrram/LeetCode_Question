class Solution {
public:
    int minAddToMakeValid(string s) {

        stack<char> st;
        int count = 0;

        int n = s.size();

        for(int i=0; i<n; i++){

            if(s[i] == '('){
                st.push(s[i]);
            }
            else{
                if(st.empty()){
                    count++;
                }
                else if(s[i] == ')' && st.top() == '('){
                    st.pop();
                }
                else 
                st.push(s[i]);
            }

        }
        return count + st.size();
   
    }
};