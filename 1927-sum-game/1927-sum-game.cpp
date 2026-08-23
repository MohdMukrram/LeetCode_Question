class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int first = 0;
        int sec = 0;
        int s1 = 0;
        int s2 = 0;
        for(int i=0;i<n/2;i++){
            if(num[i]=='?') first++;
            else s1+=(num[i]-'0');
        }
        for(int i=n/2;i<n;i++){
            if(num[i]=='?') sec++;
            else s2+=(num[i]-'0');
        }
        
        return (s1 - s2) * 2 != (sec - first) * 9;
    }
};