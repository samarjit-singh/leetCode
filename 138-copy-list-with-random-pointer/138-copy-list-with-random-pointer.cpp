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
        
//         step 1
//         suppose we have 7 & 13 in test case 1 with the below code
//         we are inserting copy of first node i.e 7 between
//         7 and 13 so it becomes 7->7->13
        while(current){
            next = current->next; //13
            Node* copy = new Node(current->val);  //copy = 7
            current->next = copy; // 7->copy(7)
            copy->next = next; //copy(7)->13
            
            current = next; //bringing 7 to 13
        }
//         after while loop we will get
//         7->7->13->13->11->11->10->10->1->null
        
//         now we have to connect random pointers
        
        
//         step 2
//         bring back current to head
        current = head;
        while(current){
            if(current->random){
//                 from test case
//                 copy(13)->random         13->random(0)->copy(7)
                current->next->random = current->random->next;
            }
            current = current->next->next;
        }
        
//         step 3
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