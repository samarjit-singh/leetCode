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
    int findSum(TreeNode* root,int& tilt){
        if(root==NULL){
            return 0;
        }
        
        int left = findSum(root->left,tilt);
        int right = findSum(root->right,tilt);
        
        tilt += abs(left-right);
        
        return left+right+root->val;
    }
    
    int findTilt(TreeNode* root) {
        int tilt = 0;
        findSum(root,tilt);
        return tilt;
    }
};

// 