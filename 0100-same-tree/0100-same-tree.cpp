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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;

        q1.push(p);
        q2.push(q);

        while(!q1.empty() && !q2.empty()){
            TreeNode* top1 = q1.front();
            q1.pop();

            TreeNode* top2 = q2.front();
            q2.pop();

            if(!top1 || !top2 || top1->val != top2->val){
                return false;
            }

            if(top1->left || top2->left){
                if (!top1->left || !top2->left) return false;
                q1.push(top1->left);
                q2.push(top2->left);
            }

            if(top1->right || top2->right){
                if (!top1->right || !top2->right) return false;
                q1.push(top1->right);
                q2.push(top2->right);
            }
        }

        return true;
    }
};