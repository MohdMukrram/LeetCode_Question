class Solution {
public:
    unordered_map<string,bool> mp;
    bool isConcatenate(string word , unordered_set<string>& st){
        if(mp.count(word)) return mp[word];
        for(int j=0;j<word.size();j++){
            string pre = word.substr(0,j+1);
            string suff = word.substr(j+1);

            if(st.count(pre) && isConcatenate(suff,st) || st.count(pre) && st.count(suff)){
                return mp[word] = true;
            }
        }
        return mp[word] = false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int n = words.size();

        unordered_set<string> st(words.begin(),words.end());

        vector<string> ans;

        for(int i=0;i<n;i++){
            string word = words[i];
            if(isConcatenate(word,st)){
                ans.push_back(word);
            }
        }
        return ans;
    }
};