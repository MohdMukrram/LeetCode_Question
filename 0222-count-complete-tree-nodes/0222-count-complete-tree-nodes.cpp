class Solution {
public:

    int leftHeight(TreeNode* root) {
        int h = 0;

        while(root) {
            h++;
            root = root->left;
        }

        return h;
    }

    int rightHeight(TreeNode* root) {
        int h = 0;

        while(root) {
            h++;
            root = root->right;
        }

        return h;
    }

    int countNodes(TreeNode* root) {

        if(!root)
            return 0;

        int lh = leftHeight(root);
        int rh = rightHeight(root);

        // Perfect binary tree
        if(lh == rh) return (1 << lh) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};