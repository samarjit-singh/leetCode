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
    
    int PreIndex = 0;
    
    TreeNode* buildTreeUtil(vector<int>& preorder, vector<int>& inorder, int inorderStart ,int inorderEnd) {
        
        if(inorderStart>inorderEnd){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[PreIndex]);
        
        PreIndex++;
        
        int inorderIndex;
        
        for(int i=inorderStart; i<=inorderEnd;i++){
            if(inorder[i]==root->val){
                inorderIndex = i;
                break;
            }
        }
        
        root->left = buildTreeUtil(preorder,inorder,inorderStart,inorderIndex-1);
        root->right = buildTreeUtil(preorder,inorder,inorderIndex+1,inorderEnd);
        
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* ans = buildTreeUtil(preorder,inorder,0,inorder.size()-1);
        return ans;
    }
};