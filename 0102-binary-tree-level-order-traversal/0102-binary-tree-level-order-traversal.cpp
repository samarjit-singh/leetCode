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

        if(root == NULL) return {};

        vector<vector<int>> res;

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


            res.push_back(temp);
        }

        return res;
    }
};