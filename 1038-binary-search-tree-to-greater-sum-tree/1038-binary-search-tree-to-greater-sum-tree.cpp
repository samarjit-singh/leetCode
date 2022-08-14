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
    
    int sum = 0;
    void dfs(TreeNode* root){
        
        if(root==NULL){ // if root is = NULL
            return;
        }
        
        dfs(root->right);// go to right
        
        root->val += sum; // add sum in root val
        sum = root->val;//update sum with root value
        dfs(root->left); // go to left
        // return;
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        dfs(root);
        return root;
    }
};