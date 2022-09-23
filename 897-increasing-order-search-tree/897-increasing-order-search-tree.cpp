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
    TreeNode* current = new TreeNode(0);
    
    void helper(TreeNode* node){
        
        if(node==NULL){
            return;
        }
        
        helper(node->left);
        node->left = NULL;
        current->right = node;
        current = node;
        helper(node->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* ans = current;
        helper(root);
        return ans->right;
    }
};