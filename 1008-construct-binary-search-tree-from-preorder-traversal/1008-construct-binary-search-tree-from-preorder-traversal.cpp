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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() == 0){
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        if(preorder.size() == 1){
            return root;
        }
        
        vector<int> left_node;
        vector<int> right_node;
        
        for(int n:preorder){
            if(n<preorder[0]){
                left_node.push_back(n);
            } else if(n>preorder[0]){
                right_node.push_back(n);
            }
        }
        
        root->left = bstFromPreorder(left_node);
        root->right = bstFromPreorder(right_node);
        
        return root;
    }
};