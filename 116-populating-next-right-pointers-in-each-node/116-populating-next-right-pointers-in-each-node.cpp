/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL){
            return NULL;
        }
        
//         making current point to root node
        Node* current = root;
        
//         till there are no nodes
//         we are doing it for each level
        while(current->left){
            
//             making another pointer temp and making it point to current
//             beacuse we need current for moving forward
            Node* temp = current;
            
            while(current){
//                 for test case 1
//                 suppose current is at root node
                current->left->next = current->right;
                current->right->next = current->next == NULL ? NULL : current->next->left;
                current = current->next;
            }
//             moving to next level
//             we cannot do current->left because it is NULL
            current = temp->left;
            
        }
        
        return root;
    }
};