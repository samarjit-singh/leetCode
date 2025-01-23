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
    int getMinimumDifference(TreeNode* root) {
        int diff = INT_MAX;
        int prevEle = -1;
        stack<TreeNode*> s;

       while (root || !s.empty()) {
            while (root) {
                s.push(root);
                root = root->left;
            }

            root = s.top();
            s.pop();
            
            if (prevEle != -1) {
                diff = min(diff, abs(root->val - prevEle));
            }
            prevEle = root->val;

            // Move to the right subtree.
            root = root->right;
        }

        return diff;
    }
};