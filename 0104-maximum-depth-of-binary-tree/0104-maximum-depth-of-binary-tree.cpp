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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        queue<pair<TreeNode*, int>> q;
        int level = 1;

        q.push({root, 1});

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            level = node.second;

            if(node.first->left){
                q.push({node.first->left, node.second + 1});
            }

            if(node.first->right){
                q.push({node.first->right, node.second + 1});
            }
        }

        return level;
    }
};