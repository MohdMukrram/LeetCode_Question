class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0) return 0;
        long long ans = 0;
        string x = "";
        long long sum = 0;
        while(n>0){
            int digi = n%10;
            if(digi != 0) x += (digi + '0');
            sum += digi;
            n/=10;
        }
        reverse(x.begin(),x.end());

        int a = stoi(x);

        ans = a*sum;
        return ans;
    }
};