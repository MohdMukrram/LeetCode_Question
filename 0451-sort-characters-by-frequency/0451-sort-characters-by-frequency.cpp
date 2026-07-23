class Solution {
public:
    typedef pair<int, char> pi;
    string frequencySort(string s) {
        priority_queue<pi> pq;
        unordered_map<char, int> m;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            m[s[i]]++;
        }
        for(auto x : m) {
            pq.push({x.second, x.first});
        }
        string ans;
        while(!pq.empty()) {
            int freq = pq.top().first;
            char ch = pq.top().second;
            pq.pop();
            ans += string(freq, ch);
        }
        return ans;
    }
};