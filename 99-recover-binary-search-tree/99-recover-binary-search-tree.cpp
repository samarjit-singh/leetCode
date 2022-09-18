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
    
    void swap(int* a,int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    
    void recoverTreeUtil(TreeNode* root,TreeNode** first,TreeNode** mid,TreeNode** last,TreeNode** prev){
        if(root==NULL){
            return;
        }
        recoverTreeUtil(root->left,first,mid,last,prev);
        
        // according to rule of BST root value should always be greater than previous val
        if(*prev && root->val < (*prev)->val){     //property is violating    
            if(!*first){ // if its violating for the first time
                *first = *prev;
                *mid = root;
            } else {
                *last = root;
            }
        } 
        *prev = root;
        recoverTreeUtil(root->right,first,mid,last,prev);
    }
    
    void recoverTree(TreeNode* root) {
        TreeNode* first, *mid,*last,*prev;
        first = NULL;
        mid = NULL;
        last = NULL;
        prev = NULL;
        
        recoverTreeUtil(root,&first,&mid,&last,&prev);
        
        if(first && last){
            swap(&first->val,&last->val);
        } else {
            swap(&first->val,&mid->val);
        }
    }
};