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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};

        vector<vector<int>> levelOrder;

        queue<TreeNode*> q;
        int levelSize = 0;
        q.push(root);

        while(!q.empty()) {
            levelSize = q.size();
            vector<int> temp;

            for(int i=0;i<levelSize;i++) {
                TreeNode* curr = q.front();
                q.pop();

                temp.push_back(curr->val);

                if(curr->left) {
                    q.push(curr->left);
                }
                if(curr->right) {
                    q.push(curr->right);
                }
            }

            levelOrder.push_back(temp);
        }

        vector<int> res;

        for(int i=0;i<levelOrder.size();i++) {
            res.push_back(levelOrder[i][levelOrder[i].size()-1]);
        }

        return res;
    }
};