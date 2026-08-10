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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "null,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    TreeNode* build(vector<string>& nodes, int& index) {
        if (nodes[index] == "null") {
            index++;
            return NULL;
        }
        // create node
        TreeNode* node = new TreeNode(stoi(nodes[index++]));
        node->left = build(nodes, index);   // recursively build left
        node->right = build(nodes, index);  // recursively build right
        return node;
    }

    // Decodes your encoded data to tree.
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

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));