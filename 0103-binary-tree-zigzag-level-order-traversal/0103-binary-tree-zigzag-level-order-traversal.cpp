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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        int f = 0;
        vector<vector<int>> ans;
        
        while(!q.empty()){
            vector<int> v;
            int s = q.size();

            for(int i=0;i<s;i++){
                TreeNode* node = q.front();
                q.pop();
                v.push_back(node->val);
                if (node->left) q.push(node->left);

                if (node->right) q.push(node->right);
                
            }

            if(f == 0) ans.push_back(v);
            else{
                reverse(v.begin(),v.end());
                ans.push_back(v);
            }

            f= !f;
        }
        return ans;
    }
};