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
    int diameter = 0;
    int util (TreeNode* root){
        if(root == nullptr){
            return 0;
        }

        int left_depth = util(root->left);
        int right_depth = util(root->right);

        diameter = max(diameter, left_depth+right_depth);

        return 1 + max(left_depth,right_depth);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        util(root);

        return diameter;
    }
};