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
    int res = 0;
    int dfs(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }

        int left = dfs(root->left);
        int right = dfs(root->right);

        res = max(res, left+right);

        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        
        dfs(root);

        return res;
    }
};

// in this problem we are finding height of binary tree in dfs
// at each node we are taking raight + left from both the sides
// and then when moving up in the tree we take max from left or right