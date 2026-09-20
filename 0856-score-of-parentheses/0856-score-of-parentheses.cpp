class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> stack;
        int currentScore = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                stack.push(currentScore);
                currentScore = 0;
            } else {
                int lastScore = stack.top();
                stack.pop();
                currentScore = lastScore + std::max(1, 2 * currentScore);
            }
        }
        return currentScore;
    }
};