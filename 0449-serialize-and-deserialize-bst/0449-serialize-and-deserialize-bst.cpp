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

    void split(string& data, queue<string>& nodes) {
        stringstream ss(data);
        string item;

        while(getline(ss, item, ',')) {
            nodes.push(item);
        }
    }

    TreeNode* BuildTree(queue<string>& nodes) {
        string val = nodes.front();
        nodes.pop();

        if(val == "null") return nullptr;

        TreeNode* node = new TreeNode(stoi(val));
        node->left = BuildTree(nodes);
        node->right = BuildTree(nodes);

        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> nodes;
        split(data, nodes);
        return BuildTree(nodes);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;