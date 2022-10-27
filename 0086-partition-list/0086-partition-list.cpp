/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // make two listNode left and right
        ListNode* left = new ListNode(-1); 
        ListNode* right = new ListNode(-1);
//         make another two tail node pointing to left and right
        ListNode* ltail = left;
        ListNode* rtail = right;
        
        while(head!=NULL){
            if(head->val < x){ // if head val is smaller than x 
                ltail->next = head; // make ltail next point to head 
                ltail = ltail->next; // move ltail forward
            } else { // if not then right
                rtail->next = head; //make rtail next point to head
                rtail = rtail->next; //move rtail forward
            }
            head = head->next; //head will move forward to iterate over the input list everytime
        }
        
//         now ltail next is pointing to NULL make it poiny to right
        ltail->next = right->next; // right is -1 so point it to right next
        rtail->next = NULL;
        return left->next;
    }
};