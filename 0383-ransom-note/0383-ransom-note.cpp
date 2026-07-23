class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.size();
        int m = magazine.size();

        unordered_map<char,int> mp;
        for(auto x : magazine) mp[x]++;
        for(auto x : ransomNote){
                if(!mp.count(x)) return false;
                else{
                    mp[x]--;
                    if(mp[x] == 0) mp.erase(x);
                }
            }

        return true;
    }
};