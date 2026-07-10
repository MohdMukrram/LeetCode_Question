class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                     vector<vector<int>>& queries) {

        vector<pair<int,int>> arr;
        for (int i = 0; i < n; i++)
            arr.push_back({nums[i], i});

        sort(arr.begin(), arr.end());

        vector<int> pos(n);
        for (int i = 0; i < n; i++)
            pos[arr[i].second] = i;

        // farthest index reachable in one edge
        vector<int> nxt(n);
        int r = 0;
        for (int l = 0; l < n; l++) {
            while (r + 1 < n && arr[r + 1].first - arr[l].first <= maxDiff)
                r++;
            nxt[l] = r;
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n));
        up[0] = nxt;

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                up[k][i] = up[k - 1][up[k - 1][i]];
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = pos[q[0]];
            int rPos = pos[q[1]];

            if (l > rPos) swap(l, rPos);

            if (l == rPos) {
                ans.push_back(0);
                continue;
            }

            if (nxt[l] == l) {
                ans.push_back(-1);
                continue;
            }

            int cur = l;
            int steps = 0;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][cur] < rPos) {
                    steps += (1 << k);
                    cur = up[k][cur];
                }
            }

            if (nxt[cur] < rPos)
                ans.push_back(-1);
            else
                ans.push_back(steps + 1);
        }

        return ans;
    }
};