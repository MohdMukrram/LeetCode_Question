class Solution {
public:
    bool ispalindrom(string s){
        int n = s.size();
        int i=0,j=n-1;

        while(i<=j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    bool isPalindrome(string s) {
        string s1 = "";

        for(char ch : s){
            if(isalnum(ch)){
                s1 += tolower(ch);
            }
            
        }

        return ispalindrom(s1);
    }
};