class Solution {
public:
    // DSU find with path compression
    int find(vector<int>& parent, int x) {
        return parent[x] == x ? x : parent[x] = find(parent, parent[x]);
    }

    // DSU union by size
    void Union(vector<int>& parent, vector<int>& size, int x, int y) {
        int px = find(parent, x);
        int py = find(parent, y);
        if (px == py) return;         // already in same set
        parent[py] = px;              // merge py into px
        size[px] += size[py];         // update size
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> parent(n * n), size(n * n, 0);
        vector<int> dir = {0,1,0,-1,0};

        // Step 1: Initialize DSU
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int idx = i * n + j;
                parent[idx] = idx;
                if (grid[i][j] == 1) size[idx] = 1;
            }
        }

        // Step 2: Union adjacent 1s
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 1) continue;
                int idx = i * n + j;
                for (int d = 0; d < 4; d++) {
                    int ni = i + dir[d], nj = j + dir[d+1];
                    if (ni < 0 || nj < 0 || ni >= n || nj >= n) continue;
                    if (grid[ni][nj] == 1) {
                        Union(parent, size, idx, ni * n + nj);
                    }
                }
            }
        }

        // Step 3: Try flipping each 0
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> seen;
                    int sum = 1; // include the flipped 0
                    for (int d = 0; d < 4; d++) {
                        int ni = i + dir[d], nj = j + dir[d+1];
                        if (ni < 0 || nj < 0 || ni >= n || nj >= n) continue;
                        if (grid[ni][nj] == 1) {
                            int p = find(parent, ni * n + nj);
                            if (seen.count(p)) continue;
                            sum += size[p];
                            seen.insert(p);
                        }
                    }
                    res = max(res, sum);
                }
            }
        }

        // Step 4: All 1s case
        for (int i = 0; i < n*n; i++) res = max(res, size[find(parent,i)]);

        return res;
    }
};
