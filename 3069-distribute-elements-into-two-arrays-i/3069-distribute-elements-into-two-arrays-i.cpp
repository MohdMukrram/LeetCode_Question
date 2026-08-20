class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> a, b;

        a.push_back(nums[0]);
        b.push_back(nums[1]);

        for (int i = 2; i < n; i++) {
            int lastA = a.back();
            int lastB = b.back();

            if (lastA > lastB) {
                a.push_back(nums[i]);
            } else {
                b.push_back(nums[i]);
            }
        }

        for (int x : b) {
            a.push_back(x);
        }

        return a;
    }
};