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
    int pathSumUtil(TreeNode* root,long sum){
        if(!root){
            return 0;
        }
        
        // int res = 0;
        
        // if(root->val == sum) res++;
        
//         res += pathSumUtil(root->left, sum-root->val);
//         res += pathSumUtil(root->right, sum-root->val);
        
//         return res;
        return (root->val == sum) + pathSumUtil(root->left, sum-root->val) + pathSumUtil(root->right, sum-root->val);
    }
    
    int pathSum(TreeNode* root, long targetSum) {
        if(root==NULL){
            return 0;
        }
        
        return pathSumUtil(root,targetSum) + pathSum(root->left,targetSum) + pathSum(root->right,targetSum);
    }
};