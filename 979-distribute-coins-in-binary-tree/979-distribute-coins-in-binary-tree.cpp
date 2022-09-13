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
    int steps = 0;
    int distr(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left = distr(root->left);
        int right = distr(root->right);
        steps += abs(left) + abs(right);
        return left+right+root->val-1;
    }
    int distributeCoins(TreeNode* root) {
        distr(root);
        return steps;
    }
};