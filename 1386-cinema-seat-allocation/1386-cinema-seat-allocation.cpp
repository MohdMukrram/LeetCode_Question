class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> mp;

        for (auto x : reservedSeats) {
            mp[x[0]].push_back(x[1]);
        }

        int ans = (n - mp.size()) * 2;

        for (auto &[row, seats] : mp) {
            set<int> s(seats.begin(), seats.end());

            bool left = true;
            bool middle = true;
            bool right = true;

            for (int seat : {2, 3, 4, 5}) {
                if (s.count(seat)) left = false;
            }

            for (int seat : {4, 5, 6, 7}) {
                if (s.count(seat)) middle = false;
            }

            for (int seat : {6, 7, 8, 9}) {
                if (s.count(seat)) right = false;
            }

            if (left && right) ans += 2;
            else if (left || middle || right) ans += 1;
        }

        return ans;
    }
};