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
    vector<TreeNode*> inorder; // for soring the inorder traversal
    
    void findInoder(TreeNode* root){
        if(root==NULL){
            return;
        }
//         inorder traversal is left root right
        findInoder(root->left);
        inorder.push_back(root);
        findInoder(root->right);
    }
    
    TreeNode* buildTree(int start,int end){
        if(start>end){ //if start is greater than end 
            return NULL; //return NULL
        }
        int mid = (start+end)/2;
        TreeNode* root = inorder[mid]; //make inorder mid as the root BST
        root->left = buildTree(start,mid-1); //for left sub tree run the loop from start to mid-1
        root->right = buildTree(mid+1,end); // for right sub tree run the loop from mid+1 to end
        return root; //return the root
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        if(!root){
            return NULL;
        }
        findInoder(root);
        int n = inorder.size();
        root = buildTree(0,n-1);
        return root;
    }
};