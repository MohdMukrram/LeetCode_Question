/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void mapParentNodes(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentMap) {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            auto node = q.front();
            q.pop();
            if(node->left){
                parentMap[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parentMap[node->right] = node;
                q.push(node->right);
            }
        }
    }

    vector<int> bfsFromTarget(TreeNode* target, unordered_map<TreeNode*, TreeNode*>& parentMap, int k) {
        queue<TreeNode*> q;
        unordered_set<TreeNode*> vis;

        q.push(target);
        vis.insert(target);
        int currLevel = 0;
        while(!q.empty()){
            int size = q.size();
            if(currLevel ++ == k) break;

            for(int i=0;i<size;i++){
                auto node = q.front();
                q.pop();

                if(node->left && !vis.count(node->left)){
                    q.push(node->left);
                    vis.insert(node->left);
                }

                if(node->right && !vis.count(node->right)){
                    q.push(node->right);
                    vis.insert(node->right);

                }

                if(parentMap.count(node) && !vis.count(parentMap[node])){
                    vis.insert(parentMap[node]);
                    q.push(parentMap[node]);
                }
            }
        }
            

        // All nodes in queue are now at distance K from the target
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }

        return result;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (!root) return {};

        // Step 1: Build parent mapping for each node using BFS
        unordered_map<TreeNode*, TreeNode*> parentMap;
        mapParentNodes(root, parentMap);

        // Step 2: Perform BFS from target to find nodes at distance K
        return bfsFromTarget(target, parentMap, k);
    }
};