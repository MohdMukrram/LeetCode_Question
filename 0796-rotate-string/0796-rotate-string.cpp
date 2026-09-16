class Solution {
public:
    bool KMP(string text, string pattern){
        int n = text.size(), m = pattern.size();
        vector<int> lps(m);

        // build lps
        for(int i=1,len=0;i<m;){
            if(pattern[i]==pattern[len]){
                lps[i++] = ++len;
            } else if(len){
                len = lps[len-1];
            } else {
                lps[i++] = 0;
            }
        }

        // search
        for(int i=0,j=0;i<n;){
            if(text[i]==pattern[j]){
                i++; j++;
            }
            if(j==m) return true;
            else if(i<n && text[i]!=pattern[j]){
                if(j) j = lps[j-1];
                else i++;
            }
        }
        return false;
    }

    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
        return KMP(goal + goal, s);
    }
};