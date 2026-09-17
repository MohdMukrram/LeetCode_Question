class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        stack<int> st;
        int mx = 0;
        int curr = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                curr++;
            }
            else if(s[i] == ')'){
                mx = max(mx,curr);
                curr--;
            }
        }
        return mx;
    }
};