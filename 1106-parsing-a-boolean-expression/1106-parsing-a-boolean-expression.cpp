class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        
        for(char ch : expression) {
            
            if(ch == ',') continue;  // ignore commas
            
            if(ch != ')') {
                st.push(ch);
            }
            else {
                // collect values inside ()
                vector<char> values;
                
                while(st.top() != '(') {
                    values.push_back(st.top());
                    st.pop();
                }
                
                st.pop(); // remove '('
                
                char op = st.top();
                st.pop();
                
                char result;
                
                if(op == '!') {
                    // only one value
                    result = (values[0] == 't') ? 'f' : 't';
                }
                else if(op == '&') {
                    result = 't';
                    for(char v : values) {
                        if(v == 'f') {
                            result = 'f';
                            break;
                        }
                    }
                }
                else { // '|'
                    result = 'f';
                    for(char v : values) {
                        if(v == 't') {
                            result = 't';
                            break;
                        }
                    }
                }
                
                st.push(result);
            }
        }
        
        return st.top() == 't';
    }
};