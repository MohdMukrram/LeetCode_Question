class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;

        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0,0}});

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            TreeNode* node = it.first;
            int col = it.second.first;
            int row = it.second.second;

            nodes[col][row].insert(node->val);

            if(node->left)
                q.push({node->left, {col-1, row+1}});
            if(node->right)
                q.push({node->right, {col+1, row+1}});
        }

        vector<vector<int>> ans;

        for(auto &p : nodes){
            vector<int> colNodes;
            for(auto &q : p.second){
                colNodes.insert(colNodes.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(colNodes);
        }

        return ans;
    }
}; 