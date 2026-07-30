class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i=0,j=0;

        while(j<n){
            char ch = chars[j];
            int count = 0;

            while(j<n && chars[j] == ch){
                j++;
                count++;
            }

            chars[i++] = ch;

            if(count > 1){
                string cnt = to_string(count);
                for(char x : cnt){
                    chars[i++] = x;
                }
            }
        }
        
        return i;
    }
};