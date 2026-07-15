class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int S_odd = 0 , S_even = 0;

        int c=1;
        for(int i=0;i<n;i++){
            S_odd+=c;
            c +=2;
        }

        int d=2;
        for(int i=0;i<n;i++){
            S_even+=d;
            d +=2;
        }

        return __gcd(S_odd,S_even);
    }
};