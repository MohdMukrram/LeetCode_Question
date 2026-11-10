class Solution {
public:
        int reverse(int x) {
        int result = 0;
        int sign = (x < 0) ? -1 : 1;
        x=abs(x);  
        while(x!=0){
            int digit =x%10;
            x/=10;
            if (result > (INT_MAX - digit) / 10) {
                return 0;  // Overflow
            }
            result = result * 10 + digit;
        }
        return result * sign;
    }
};