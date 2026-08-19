/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string serialize(TreeNode* root) {
        if(!root) return "null,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    TreeNode* build(vector<string>& nodes, int& index) {
        if (nodes[index] == "null") {
            index++;
            return NULL;
        }
        TreeNode* node = new TreeNode(stoi(nodes[index++]));
        node->left = build(nodes, index);
        node->right = build(nodes, index);
        return node;
    }
    TreeNode* deserialize(string data) {
        vector<string> nodes;
        string val;
        stringstream ss(data);
        // Split the serialized string by comma
        while (getline(ss, val, ',')) {
            nodes.push_back(val);
        }
        int index = 0;
        return build(nodes, index);
    }
};