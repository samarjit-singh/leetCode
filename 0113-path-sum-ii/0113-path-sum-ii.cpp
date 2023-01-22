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
    
    void preorder(TreeNode* root,int target,int sum,vector<vector<int>>& ans,vector<int>& path){
        if(root==NULL) return;
        
        sum += root->val;
        path.push_back(root->val);
        
        if(sum == target and root->left == NULL and root->right==NULL){
            ans.push_back(path);
        }
        
        preorder(root->left,target,sum,ans,path);
        preorder(root->right,target,sum,ans,path);
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        preorder(root,targetSum,0,ans,path);
        return ans;
    }
};