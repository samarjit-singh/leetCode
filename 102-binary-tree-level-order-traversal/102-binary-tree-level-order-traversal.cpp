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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL){
            return{};
        }
        vector<vector<int>> result;
        
        queue<TreeNode*> que;
        
        que.push(root);
        
        while(!que.empty()){
            int n = que.size();
            vector<int> level_order;
            
            for(int i=0;i<n;i++){
                TreeNode* node = que.front();
                que.pop();
                
                if(node->left){
                    que.push(node->left);
                }
                
                if(node->right){
                    que.push(node->right);
                }
                
                level_order.push_back(node->val);
            }
            result.push_back(level_order);
        }
        return result;
    }
};