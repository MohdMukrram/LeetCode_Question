class Solution {
public:
    int minChanges(string s) {
        char curr = s[0];
        int count =0;
        int change =0;
        int n = s.size();

        for(int i=0;i<n;i++){
            if(s[i]==curr){
                count++;
                continue;
            }
            else if(count%2==0){
                count=1;
            }
            else{
                count = 0;
                change++;
            }
            curr = s[i];
        }
        return change;
    }
};