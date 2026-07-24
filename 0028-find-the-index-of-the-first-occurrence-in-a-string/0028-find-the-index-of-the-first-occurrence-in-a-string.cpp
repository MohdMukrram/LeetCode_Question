class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();;
        int m = needle.size();

        if(m > n) return -1;

        int i=0,j=0;

        while(j<=n){
            while(j-i+1 > m){
                if(needle == haystack.substr(i,m)) return i;
                i++;
            }
            j++;
        }
        return -1;
    }
};