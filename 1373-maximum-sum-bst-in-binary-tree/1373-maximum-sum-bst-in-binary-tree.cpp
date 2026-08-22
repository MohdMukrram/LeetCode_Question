class Solution {
public:
    int ans = 0;

    // {minimum, maximum, sum}
    vector<int> solve(TreeNode* root) {
        // Empty tree is a BST
        if (root == NULL) {
            return {INT_MAX, INT_MIN, 0};
        }

        vector<int> left = solve(root->left);
        vector<int> right = solve(root->right);

        // Check whether current subtree is BST
        if (left[1] < root->val && root->val < right[0]) {

            int sum = left[2] + right[2] + root->val;

            ans = max(ans, sum);

            int minimum = min(root->val, left[0]);
            int maximum = max(root->val, right[1]);

            return {minimum, maximum, sum};
        }

        // Not a BST
        return {INT_MIN, INT_MAX, 0};
    }

    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};