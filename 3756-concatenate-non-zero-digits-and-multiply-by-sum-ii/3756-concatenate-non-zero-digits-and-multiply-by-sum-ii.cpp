class Solution {
public:
    using ll = long long;
    
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        ll n = s.length(), m = queries.size(), MOD = 1e9 + 7;
        vector<ll> pre(n), count(n), sum(n), pow10(n + 1); pow10[0] = 1;

        for(int i = 1; i <= n; ++i)
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        
        for(int i = 0; i < n; ++i) {
            int dig = (s[i] - '0');

            if(i) 
                pre[i] = pre[i - 1], sum[i] = sum[i - 1], count[i] = count[i - 1];
            
            if(dig) 
                pre[i] = (pre[i] * 10 + dig) % MOD, sum[i] += dig, count[i] += 1;
        }

        int i = 0;
        vector<int> res(m);

        for(auto& query : queries) {
            int l = query[0], r = query[1];
            ll cnt = count[r] - (l ? count[l - 1] : 0);

            if(!cnt)
                res[i] = 0;

            else {
                ll dig_sum = sum[r] - (l ? sum[l - 1] : 0);
                ll left_sum = l ? pre[l - 1] : 0;
                ll px = (pre[r] - left_sum * pow10[cnt]) % MOD;

                if(px < 0)
                    px += MOD;

                res[i] = (px * dig_sum) % MOD;
            }
            
            ++i;
        }

        return res;
    }
};