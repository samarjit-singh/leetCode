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
    
    int leftChildren,rightChildren;
    
    int count(TreeNode* root,int x){
        if(root==NULL){
            return 0;
        }
        int left = count(root->left,x);
        int right = count(root->right,x);
        
        if(root->val==x){
            leftChildren = left;
            rightChildren = right;
        }
        return left+right+1;
    }
    
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        leftChildren = 0;
        rightChildren = 0;
        count(root,x);
        int countOfParentNodesExcludingX = n-(leftChildren+rightChildren+1);
        int maximum = max(countOfParentNodesExcludingX,max(leftChildren,rightChildren));
        return maximum>(n/2);
    }
};