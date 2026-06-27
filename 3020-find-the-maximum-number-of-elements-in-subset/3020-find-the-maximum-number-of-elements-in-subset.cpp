class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;

        for (int x : nums)
            freq[x]++;

        int ans = 1;

        // Handle 1 separately
        if (freq.count(1)) {
            int cnt = freq[1];
            ans = max(ans, (cnt % 2 == 0) ? cnt - 1 : cnt);
        }

        for (auto &[x, cnt] : freq) {
            if (x == 1) continue;

            long long cur = x;
            int len = 0;

            while (freq.count(cur)) {
                if (freq[cur] >= 2) {
                    len += 2;
                    if (cur > 1000000000LL / cur) break; // prevent overflow
                    cur = cur * cur;
                } else {
                    len += 1;
                    break;
                }
            }

            if (len % 2 == 0) len--;
            ans = max(ans, len);
        }

        return ans;
    }
};