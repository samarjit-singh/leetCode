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
    
    // int getLength(ListNode* head){
    //     int len = 0;
    //     ListNode* temp = head;
    //     while(temp){
    //         len++;
    //         temp = temp->next;
    //     }
    //     return len;
    // }
    
    ListNode* middleNode(ListNode* head) {
//         if(head){
//             int len = getLength(head);
//             ListNode* temp = head;
            
//             int middleIndex = len / 2;
            
//             while(middleIndex--){
//                 temp = temp->next;
//             }
//             return temp;
//         }
//         return NULL;
        
        ListNode* slowPointer = head;
        ListNode* fastPointer = head;
        
        if(head!=NULL){
            while(fastPointer != NULL && fastPointer->next != NULL){
                fastPointer = fastPointer->next->next;
                slowPointer = slowPointer->next;
            }
            return slowPointer;
        }
        return NULL;
    }
};