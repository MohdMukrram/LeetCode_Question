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
    TreeNode* solve(vector<int>& post, vector<int>& in, int s, int e, int &idx){
        if(s>e) return NULL;
        int i = s;
        int rootVal = post[idx];
        while(i<=e){
            if(in[i] == rootVal) break;
            i++;
        }
        idx--;
        TreeNode* root = new TreeNode(rootVal);
        root->right = solve(post,in,i+1,e,idx);
        root->left = solve(post,in,s,i-1,idx);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int idx = n-1;
        return solve(postorder,inorder,0,n-1,idx);
    }
};