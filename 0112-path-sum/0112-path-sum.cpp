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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root){
            return false;
        }
        
        queue<pair<TreeNode*,int>> q;

        q.push({root, root->val});

        while(!q.empty()){
            auto top = q.front();
            q.pop();

            TreeNode* current = top.first;
            int currentSum = top.second;

            if(!current->left && !current->right && currentSum == targetSum){
                return true;
            }

            if(current->left){
                q.push({current->left, currentSum + current->left->val});
            }

            if(current->right){
                q.push({current->right, currentSum + current->right->val});
            }
        }

        return false;
    }
};