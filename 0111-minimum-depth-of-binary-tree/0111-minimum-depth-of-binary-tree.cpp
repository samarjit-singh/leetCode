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
    int minDepth(TreeNode* root) {
        if (root==NULL){ // if root is NULL
            return 0; // return NULL
        }
        
        if(root->right == NULL && root->left==NULL){
            return 1;
        }
        
        if(root->left == NULL){
            return 1 + minDepth(root->right);
        }
        
        if(root->right == NULL){
            return 1 + minDepth(root->left);
        }
        
//         else return root is at level 1 so 1 + maximum of root->left or root right
        return 1 + min(minDepth(root->left),minDepth(root->right));
    }
};