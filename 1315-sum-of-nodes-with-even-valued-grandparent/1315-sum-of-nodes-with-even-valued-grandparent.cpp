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
    int sumEvenGrandparent(TreeNode* root) {
        if(root==NULL){ // if root null
            return 0; // return 0
        }
        
        int sum = 0; // make sum for storing the sum
        
        if(root->val%2==0){ // if root value is 0
            // root left is not null and root left left is also not null
            if(root->left!=NULL && root->left->left!=NULL){
                sum+= root->left->left->val; // add its value to sum
            }
//             similarly for root left and root left right
            if(root->left!=NULL && root->left->right!=NULL){ 
                sum+= root->left->right->val;
            }
//             again for root eight right
            if(root->right!=NULL && root->right->right!=NULL){
                sum+= root->right->right->val;
            }
//             and for root right left
            if(root->right!=NULL && root->right->left!=NULL){
                sum+= root->right->left->val;
            }
        }
        
//         by doin dfs go to left then right
        sum+=sumEvenGrandparent(root->left);
        sum+=sumEvenGrandparent(root->right);
        
        return sum; // return the
    }
};