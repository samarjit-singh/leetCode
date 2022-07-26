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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        TreeNode* curr = root;
        stack<TreeNode*> st;
        
        int i = 1;
        
        while(i<preorder.size()){
            if(curr->val > preorder[i]){
                curr->left = new TreeNode(preorder[i]);
                st.push(curr);
                curr = curr->left;
            } else {
                while(!st.empty() && st.top()->val < preorder[i]){
                    curr = st.top();
                    st.pop();
                }
                curr->right = new TreeNode(preorder[i]);
                curr = curr->right;
            }
            i++;
        }
        return root;
    }
};