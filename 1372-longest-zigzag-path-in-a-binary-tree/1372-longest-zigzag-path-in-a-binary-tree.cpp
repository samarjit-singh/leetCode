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
    
    int maxi = 0;
    
    void solve(TreeNode* root,int dir,int len){
        if(root == NULL) return;
        maxi = max(maxi,len);
        
        if(dir == 0){ // comming from left
            solve(root->right,1,len+1); //go to right change direction and increment len by 1
            solve(root->left,0,1);
        } else {
            solve(root->right,1,1);
            solve(root->left,0,len+1);
        }
    }
    
    int longestZigZag(TreeNode* root) {
        solve(root->left,0,1); // reached the node by comming from left
        solve(root->right,1,1); // reached the node by comming from  right
        return maxi;
    } 
};