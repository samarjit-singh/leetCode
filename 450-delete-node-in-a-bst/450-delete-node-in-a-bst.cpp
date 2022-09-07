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
    int minVal(TreeNode* root){
        int minValue = root->val;
        while(root->left != NULL){
            minValue = root->left->val; //since its a binary tree so so our min value will be o the left
            root = root->left;
        }
        return minValue;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){ // if root is NULL
            return root; //return root
        }
        
        //if key is less tahn root
        if(key < root->val){ 
            root->left = deleteNode(root->left,key); //go to left
        } else if(key>root->val){ //if key is greater than root val
            root->right = deleteNode(root->right,key); //go to right
        } else { // if root is the element we want to delete , then we have three cases 
            if(root->left == NULL){
                return root->right;
            } else if(root->right == NULL){
                return root->left;
            }
//             now if both sides are not null we find inorder successor
            root->val = minVal(root->right);
            root->right = deleteNode(root->right,root->val);
        }
        return root;
    }
};