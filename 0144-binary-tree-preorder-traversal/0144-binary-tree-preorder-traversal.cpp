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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* node = root;

        while(node != NULL || !st.empty()) {
            if(node != NULL) {
                res.push_back(node->val);
                if(node->right) {
                    st.push(node->right);
                } 
                node = node->left;
            } else {
                node = st.top();
                st.pop();
            }
        } 

        return res;
    }
};