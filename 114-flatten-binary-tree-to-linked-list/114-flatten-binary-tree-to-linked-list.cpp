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
    void flatten(TreeNode* root) {
        if (root == NULL || (root->left == NULL && root->right == NULL)){ // base conditon
            return;
        }
        
        while(root->left!=NULL){ // if root left is not null 
            flatten(root->left); // makr a recursive call for root left
            
            TreeNode* temp = root->right;  // make a temporary variable for temp and store root right i it
            root->right = root->left; // make root right as root left
            root->left = NULL;  // and make root left as null
            
//             now check for end node of root right
//             which is actually our root left
            TreeNode* t = root->right;  
            
            while(t->right!=NULL){
                t = t->right; // this will be the end node of root right
            }
            t->right = temp; // now at the end of root right join the temp
        }
        flatten(root->right); // and now again flatten root right
    }
};