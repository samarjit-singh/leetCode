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
    void sumOfLeafNodes(TreeNode* root,bool isLeft){ 
        if(isLeft && !root->left && !root->right){ // check if the node is left and does not have left or right
            sum += root->val; // add its value to sum
            return;
        }
        if(root->left){ // make a recursive call for root left
            sumOfLeafNodes(root->left,true); // for left pass true
        }
        if(root->right){ // make a recursive call for root right
            sumOfLeafNodes(root->right,false); // for right pass return false
        }
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0; //if root does not exist return 0
        sumOfLeafNodes(root,false); // call the function
        return sum; // return the sum
    }
};