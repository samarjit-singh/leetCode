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

    TreeNode* util(TreeNode* root, TreeNode* p, TreeNode* q){

        if(root == nullptr){
            return root;
        }

        TreeNode* left = util(root->left, p, q);
        TreeNode* right = util(root->right, p, q);

        if (left && right) {
            return root;
        }

        if (root->val == p->val || root->val == q->val) {
            return root;
        }

        return left ? left : right;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = util(root, p, q);

        return res;
    }
};