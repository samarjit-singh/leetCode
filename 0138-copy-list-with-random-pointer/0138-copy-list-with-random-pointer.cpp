/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* current = head;
        Node* next;
        
        while(current){
            next = current->next;
            Node* copy = new Node(current->val);
            current->next = copy;
            copy->next = next;
            current = next;
        }
        
        current = head;
        while(current){
            if(current->random){
                current->next->random = current->random->next;
            }
            current = current->next->next;
        }
        
        current = head;
        Node* dummy = new Node(0);
        Node* copy;
        Node* copyTail = dummy;
        
        while(current){
            next = current->next->next;
            copy = current->next;
            copyTail->next = copy;
            copyTail = copy;
            
            current->next = next;
            
            current = next;
            
        }
        
        
        return dummy->next;
    }
};