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
    int preorder(TreeNode* root, int maxVal) {
        if(!root) return 0;

        int res = root->val >= maxVal ? 1 : 0;
        maxVal = max(maxVal, root->val);

        res += preorder(root->left, maxVal);
        res += preorder(root->right, maxVal);

        return res;
        
    }

    int goodNodes(TreeNode* root) {
        return preorder(root, root->val);
    }
};

// normal preorder traversal and just pass root val to each level
// and check it root->val is greater than equal to maxVal