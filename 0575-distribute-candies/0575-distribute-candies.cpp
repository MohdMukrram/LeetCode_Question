class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        unordered_set<int> st(candyType.begin(),candyType.end());

        if(n/2 <= st.size()) return n/2;
        return st.size();
    }
};