class Solution {
public:
    bool isPalindrom(int i,int j,string& s){
        while(i <= j){
            if(s[i++] != s[j--]){
                return false;
            }
        }
        return true;

    }
    void solve(string &s,int i,vector<string>& path, vector<vector<string>>& res){
        if(i == s.size()){
            res.push_back(path);
            return;
        }

        for(int k=i;k<=s.size();k++){
            if(isPalindrom(i,k,s)){
                path.push_back(s.substr(i,k-i+1));
                solve(s,k+1,path,res);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        solve(s,0,path,res);
        return res;
    }
};