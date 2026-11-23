class Solution {
public:
    void helper(vector<int>& nums, vector<int>& ans, vector<vector<int>>& finalAns, int idx, vector<bool>& used) {
        if (idx == nums.size()) {
            finalAns.push_back(ans);
            return;
        }
        
        // Skip duplicates
        if (idx > 0 && nums[idx] == nums[idx - 1] && !used[idx - 1]) {
            helper(nums, ans, finalAns, idx + 1, used);
            return;
        }
        helper(nums, ans, finalAns, idx + 1, used);

        ans.push_back(nums[idx]);
        used[idx] = true;
        helper(nums, ans, finalAns, idx + 1, used);
        ans.pop_back();
        used[idx] = false; 
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> finalAns;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        helper(nums, ans, finalAns, 0, used);
        return finalAns;
    }
};
