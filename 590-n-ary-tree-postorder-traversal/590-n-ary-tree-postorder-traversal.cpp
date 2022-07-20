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
    vector<int> postorder(Node* root) {
        if(!root){
            return {};
        }
        
        stack<Node*> st1;
        stack<Node*> st2;
        vector<int> postorder;
        
        st1.push(root);
        
        Node* current;
        
        while(!st1.empty()){
            current = st1.top();
            st1.pop();
            
            int i=0;
            
            while(i<current->children.size()){
                st1.push(current->children[i]);
                i++;
            }
            st2.push(current);
            
        }
        
        while(!st2.empty()){
            postorder.push_back(st2.top()->val);
            st2.pop();
        }
        
        
        return postorder;
    }
};