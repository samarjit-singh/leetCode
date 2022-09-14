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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        int ans = 0;
        
        queue<pair<TreeNode*,int>> q; // for storing the node value and its index at that level
        
        q.push({root,0});
        
        while(!q.empty()){
            int size = q.size();
            int min = q.front().second; //to make the index start from zero
            int first,last;
            for(int i=0;i<size;i++){
                long currentIndex = q.front().second-min;
                TreeNode* node = q.front().first;
                q.pop();
                if(i==0) first = currentIndex;
                if(i==size-1) last = currentIndex;
                if(node->left){
                    q.push({node->left,currentIndex*2+1});
                } 
                if(node->right){
                    q.push({node->right,currentIndex*2+2});
                }
            }
            ans = max(ans,last-first+1);
        }
        return ans;
        
    }
};