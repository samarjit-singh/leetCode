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
class BSTIterator {
public:
    
    stack<TreeNode*> st;
    
    BSTIterator(TreeNode* root) {
//         now we push all the left part of the stack into the stack
        inorderTraversal(root);
    }
    
    void inorderTraversal(TreeNode* root){
        while(root!=NULL){
            st.push(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode* top = st.top();  // we take top value from the stack
        st.pop(); //we pop it from the stack
        inorderTraversal(top->right);  //move to the right
        return top->val; // and return the top value
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */