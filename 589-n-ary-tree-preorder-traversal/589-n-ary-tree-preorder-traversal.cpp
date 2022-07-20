/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        stack<Node*> st;
        vector<int> preorder;
        
        if(root==NULL){
            return preorder;
        }
        
        st.push(root);
        
        while(!st.empty()){
            Node* current = st.top();
            st.pop();
            
            preorder.push_back(current->val);
            
            for(int i=current->children.size()-1;i>=0;i--){
                st.push(current->children[i]);
            }
         }
        
        return preorder;
    }
};