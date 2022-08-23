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
private:
    vector<int> Tree;
    
public:
    void inOrder(TreeNode* root){
        if(root==NULL){
            return;
        }
        inOrder(root->left);
        Tree.push_back(root->val);
        inOrder(root->right);
    }
    
    bool isValidBST(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        inOrder(root);
        for(int i=1;i<Tree.size();i++){
            if(Tree[i]<=Tree[i-1]){
                return false;
            }
            
        }
        return true;
    }
};