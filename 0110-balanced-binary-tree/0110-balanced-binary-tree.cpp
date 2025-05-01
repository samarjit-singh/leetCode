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
    bool isBalance = true;
    int dfs(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }

        int left = dfs(root->left);
        int right = dfs(root->right);

        if(abs(right - left) > 1) {
            isBalance = false;
        }

        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        dfs(root);
        return isBalance;
    }
};