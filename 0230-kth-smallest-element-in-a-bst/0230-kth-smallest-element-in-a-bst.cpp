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
    vector<int> res;
    TreeNode* dfs(TreeNode* root) {
        if(root == NULL) {
            return nullptr;
        }

        dfs(root->left);
        res.push_back(root->val);
        dfs(root->right);

        return root;
    }

    int kthSmallest(TreeNode* root, int k) {
        dfs(root);

        return res[k-1];
    }
};