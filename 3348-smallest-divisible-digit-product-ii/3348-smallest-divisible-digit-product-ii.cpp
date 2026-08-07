class Solution {
public:
    string smallestNumber(string num, long t) {
        int n = num.length();

        // Process each digit, find first zero position 
        vector<long> divisibility(n + 1);
        divisibility[0] = t;
        int firstZeroIndex = n;

        // Process each digit, find first zero position 
        for (int i = 0; i < n; i++) {
            if (num[i] == '0') {
                firstZeroIndex = i + 1;
                break;
            }
            divisibility[i + 1] = divisibility[i] / gcd(divisibility[i], num[i] - '0');
        }
        
       // If no change needed (number already divisible by t), return
        if (firstZeroIndex == n && divisibility[n] == 1) return num;

       // Traverse backwards from first zero position
        for (int i = firstZeroIndex - 1; i >= 0; i--) {
            while (num[i] < '9') {
                long tempT = divisibility[i];
                num[i]++;
                tempT /= gcd(tempT, num[i] - '0');
                
                // Try replacing trailing digits with smallest possible numbers 
                for (int j = n - 1; j > i; j--) {
                    // Start from 9 downwards as larger rightmost digits make smaller number
                    for (int k = 9; k > 0; k--) {
                        if (tempT % k == 0) {
                            tempT /= k;
                            num[j] = '0' + k;
                            break;
                        }
                    }
                }

                if (tempT == 1) return num;
            }
        }

       // factorize t into smallest factor
        string res;
        for (int i = 9; t > 1 && i > 1; i--) {
            while (t % i == 0) {
                res += to_string(i);
                t /= i;
            } 
        }

        if (t != 1) return "-1";

        reverse(res.begin(), res.end());

        // if res > num
        if (isGreaterThan(res, num)) return res;

        // If res <= number, add '1'
        int lenDif = num.length() - res.length();
        if (isGreaterThan(string(lenDif, '1') + res, num)) return string(lenDif, '1') + res;    

        // If still not greater, add one more '1'
        return string(lenDif + 1, '1') + res;
    }

    long long gcd(long long a, long long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    bool isGreaterThan(string a, string b) {
        if (a.length() == b.length()) return a > b;
        return a.length() > b.length();
    }
};