class Solution {
public:
    int minCount(vector<int>& freq){
        int mn = INT_MAX;
        for(int i =0;i<26;i++){
           if(freq[i] != 0){
              mn = min(mn,freq[i]);
           }
        }
        return (mn == INT_MAX) ? 0 : mn;
    }
    int maxCount(vector<int>& freq){
        int mx = INT_MIN;
        for(int i =0;i<26;i++){
           if(freq[i] != 0){
              mx = max(mx,freq[i]);
           }
        }
        return (mx == INT_MIN) ? 0 : mx;
    }
    int beautySum(string s) {
        int n = s.size();
        int sum = 0;

        for(int i=0;i<n;i++){
            vector<int> freq(26,0);
            for(int j=i;j<n;j++){
                freq[s[j] - 'a']++;
                int b = maxCount(freq) - minCount(freq);
                sum += b;
            }
        }
        return sum;
    }
};