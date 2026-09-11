class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);

        for (int x : digits)
            freq[x]++;

        int ans = 0;

        for (int num = 100; num <= 998; num += 2) {
            int x = num;

            int a = x / 100;
            int b = (x / 10) % 10;
            int c = x % 10;

            vector<int> need(10, 0);
            need[a]++;
            need[b]++;
            need[c]++;

            bool possible = true;

            for (int d = 0; d <= 9; d++) {
                if (need[d] > freq[d]) {
                    possible = false;
                    break;
                }
            }

            if (possible)
                ans++;
        }

        return ans;
    }
};