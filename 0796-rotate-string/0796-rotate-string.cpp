class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        int m = goal.size();
        if (n != m) return false;
        string doubled = s + s;
        for (int i = 0; i <= doubled.size() - m; i++) {
            if (doubled.substr(i, m) == goal) {
                return true;
            }
        }
        return false;
    }
};