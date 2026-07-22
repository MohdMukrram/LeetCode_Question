class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();

        sort(citations.begin(), citations.end());

        int h = 0;

        for (int i = 0; i < n; i++) {
            int papers = n - i;

            if (citations[i] >= papers) {
                h = max(h, papers);
            }
        }

        return h;
    }
};