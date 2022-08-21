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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> que;
        int sum = 0;
        int last_sum = 0;
        que.push(root);
        que.push(NULL);
        
        while(!que.empty()){
            TreeNode* top = que.front();
            que.pop();
            if(top==NULL){
                if(que.size()==0){
                    last_sum = sum;
                    break;
                }
                que.push(NULL);
                sum=0;
            } else {
                sum += top->val;
                if(top->left){
                    que.push(top->left);
                }
                if(top->right){
                    que.push(top->right);
                }
            }
        }
        return last_sum;
    }
};