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
    ListNode* reverseList(ListNode* head) {
         ListNode* prevptr = NULL;
         ListNode* currptr = head;
         ListNode* nextptr;
        
        while(currptr != NULL){
            nextptr = currptr->next; //initializinf next pointer
            currptr->next = prevptr; //current ke next ko previous ko point kr wa diya
            
            
//             moving forward the pointers
            prevptr = currptr;
            currptr = nextptr;
//             no need of moving forward the next pointer beacuse it is getting initialized at the top
            
            
        }
        
//         this is our new head
        return prevptr;
        
    }
};