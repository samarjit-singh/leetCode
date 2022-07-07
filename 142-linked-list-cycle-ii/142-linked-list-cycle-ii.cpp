/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
//         checking for an empty list
        if( head==NULL || head->next == NULL)
            return NULL;
        
//         using fast and slow approach
//         slow moves by 1 step and fast moves by 2 step
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* entry = head;
        
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next; //moving slow by 1 position
            fast = fast->next->next; //moving fast by 2 position
            
//             when slow == fast it means there is cycle
            if(slow == fast){
                while(slow != entry){ //entry is already initialized to head
                    slow = slow->next;
                    entry = entry->next; //when they come at same position that is the starting point
                }
                return entry;
            }
        }
        return NULL;
    }
};