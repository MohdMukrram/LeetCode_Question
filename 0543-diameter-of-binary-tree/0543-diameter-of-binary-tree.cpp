class Solution {
public:
    int ans = 0;

    int solve(TreeNode* root) {
        if (!root) return 0;

        int l = solve(root->left);
        int r = solve(root->right);

        ans = max(ans, l + r);

        return 1 + max(l, r);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return ans;
    }
};