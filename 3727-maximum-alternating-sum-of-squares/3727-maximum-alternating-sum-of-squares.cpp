class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        
        int n = nums.size();
        vector<long long> v;
        
        for(int x : nums){
            v.push_back(abs(x));
        }
        
        sort(v.begin(), v.end(), greater<long long>());
        
        long long score = 0;
        
        // Add first half
        for(int i = 0; i < (n + 1) / 2; i++){
            score += v[i] * v[i];
        }
        
        // Subtract second half
        for(int i = (n + 1) / 2; i < n; i++){
            score -= v[i] * v[i];
        }
        
        return score;
    }
};