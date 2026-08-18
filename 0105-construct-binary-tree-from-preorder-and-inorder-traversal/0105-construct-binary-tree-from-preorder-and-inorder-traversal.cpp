/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(vector<int>& pre, vector<int>& in, int s, int e, int &idx){
        if(s>e) return NULL;
        int i = s;
        int rootVal = pre[idx];
        while(i<=e){
            if(in[i] == rootVal) break;
            i++;
        }
        idx++;
        TreeNode* root = new TreeNode(rootVal);
        root->left = solve(pre,in,s,i-1,idx);
        root->right = solve(pre,in,i+1,e,idx);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int idx = 0;
        return solve(preorder,inorder,0,n-1,idx);
    }
};