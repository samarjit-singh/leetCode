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
    vector<int> nodes;

    TreeNode* InOrder(TreeNode* curr){
        if(curr == nullptr){
            return curr;
        }
        InOrder(curr->left);
        nodes.push_back(curr->val);
        InOrder(curr->right);

        return curr;
    }

    TreeNode* balance(vector<int>& nums, int start, int end){
        if(start > end){
            return nullptr;
        }

        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = balance(nums, start, mid-1);
        root->right = balance(nums, mid+1, end);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        TreeNode* curr = root;

        // from bst to sorted array
        InOrder(curr);

        // from array to BST  
        return balance(nodes, 0, nodes.size()-1);
    }
};