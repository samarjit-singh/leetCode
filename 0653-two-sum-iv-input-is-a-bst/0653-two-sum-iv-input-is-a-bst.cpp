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
    bool findTarget(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        set<int> s;

        while(!q.empty()){
            TreeNode* top = q.front();
            q.pop();

            if(s.find(k - top->val) != s.end()){
                return true;
            } else {
                s.insert(top->val);

                if(top->left){
                    q.push(top->left);
                }

                if(top->right){
                    q.push(top->right);
                }
            }
        }

        return false;
    }
};