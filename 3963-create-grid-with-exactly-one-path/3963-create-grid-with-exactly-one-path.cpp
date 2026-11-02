class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> res(m - 1, "." + string(n - 1, '#'));
        
        res.push_back(string(n, '.'));
        
        return res;
    }
};