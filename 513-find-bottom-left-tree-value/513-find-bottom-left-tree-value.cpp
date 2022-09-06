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
    int findBottomLeftValue(TreeNode* root) {
        if(!root){
            return 0;
        }
        
        int last = 0;
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        
        
        while(!q.empty()){
            int size = q.size();
            int count = 0;
            while(count<size){
                TreeNode* node = q.front();
                q.pop();
                
                if(count == 0) last = node->val;
                
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                count++;
            }
            
        }
        return last;
    }
};