class Solution {
public:
    struct Node {
        int prod = 1;
        int cnt[5] = {0, 0, 0, 0, 0};
    };

    int k;
    vector<Node> seg;

    Node mergeNode(const Node &a, const Node &b) {
        Node res;

        res.prod = (a.prod * b.prod) % k;

        for (int r = 0; r < k; r++) {
            res.cnt[r] += a.cnt[r];

            int nr = (a.prod * r) % k;
            res.cnt[nr] += b.cnt[r];
        }

        return res;
    }

    Node makeNode(int val) {
        Node res;
        int rem = val % k;

        res.prod = rem;
        res.cnt[rem] = 1;

        return res;
    }

    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        this->k = k;

        int n = nums.size();

        int size = 1;
        while (size < n)
            size <<= 1;

        seg.resize(2 * size);

        // Build leaves
        for (int i = 0; i < n; i++) {
            seg[size + i] = makeNode(nums[i]);
        }

        // Build tree
        for (int i = size - 1; i >= 1; i--) {
            seg[i] = mergeNode(seg[2 * i], seg[2 * i + 1]);
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Update
            nums[index] = value;

            int pos = size + index;
            seg[pos] = makeNode(value);

            pos >>= 1;

            while (pos >= 1) {
                seg[pos] = mergeNode(seg[2 * pos], seg[2 * pos + 1]);
                pos >>= 1;
            }

            // Query [start, n-1]
            int l = size + start;
            int r = size + n - 1;

            Node leftRes;
            Node rightRes;

            bool hasLeft = false;
            bool hasRight = false;

            while (l <= r) {
                if (l & 1) {
                    if (!hasLeft) {
                        leftRes = seg[l];
                        hasLeft = true;
                    } else {
                        leftRes = mergeNode(leftRes, seg[l]);
                    }
                    l++;
                }

                if (!(r & 1)) {
                    if (!hasRight) {
                        rightRes = seg[r];
                        hasRight = true;
                    } else {
                        rightRes = mergeNode(seg[r], rightRes);
                    }
                    r--;
                }

                l >>= 1;
                r >>= 1;
            }

            Node res;

            if (hasLeft && hasRight)
                res = mergeNode(leftRes, rightRes);
            else if (hasLeft)
                res = leftRes;
            else
                res = rightRes;

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};
