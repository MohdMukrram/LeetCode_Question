class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        priority_queue<int> pq;

        for (auto x : st) {
            pq.push(x);
        }
        if (pq.size() < 3) {
            return pq.top();
        }
        pq.pop();
        pq.pop();
        return pq.top();
    }
};