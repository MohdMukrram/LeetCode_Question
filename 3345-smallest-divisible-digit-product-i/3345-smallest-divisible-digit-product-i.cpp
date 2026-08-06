class Solution {
public:
    int prod(int n){
        int mul = 1;
        while(n>0){
            int digi = n%10;
            n/=10;

            mul *= digi;
        }
        return mul;
    }
    int smallestNumber(int n, int t) {
        int ans = 0;
        for(int i=n;i<=100;i++){
            int x = prod(i);
            if(x%t == 0) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};