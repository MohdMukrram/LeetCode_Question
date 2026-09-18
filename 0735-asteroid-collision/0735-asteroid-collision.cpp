class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        int n = asteroids.size();

        for(auto ast : asteroids){
            bool alive = true;
            while(!st.empty() && ast < 0 && st.top() > 0){
                if(st.top() < abs(ast)){
                    st.pop();
                    continue;
                }
                else if(st.top() == abs(ast)) st.pop();
                alive = false;
                break;
            }

            if(alive) st.push(ast);
            
        }
        
        vector<int> ans(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};