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
    bool preorder(TreeNode* root,int target,int sum){
        if(root==NULL){
            return false;
        }
        if(root->left == NULL && root->right==NULL){
            return ((root->val)+sum == target);
        }
        
        bool left = preorder(root->left,target,sum+root->val);
        bool right = preorder(root->right,target,sum+root->val);
        
        return(left||right);
        
    }
    bool hasPathSum(TreeNode* root, int trgetSum) {
        return preorder(root,trgetSum,0);
    }
};