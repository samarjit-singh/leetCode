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
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int result = 0;
        kthinorder(root,k,count,result);
        return result;
    }
    void kthinorder(TreeNode* root,int k,int& count,int& result){
        if(root->left){
            kthinorder(root->left,k,count,result);
        }
        count++;
        if(count==k){
            result = root->val;
            return;
        }
        if(root->right){
            kthinorder(root->right,k,count,result);
        }
    }
};