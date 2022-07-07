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
    bool hasCycle(ListNode *head) {
        
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next && fast->next->next){
            slow = slow->next; //move slow by one position
            fast = fast->next->next;  //move fast by two postion
            
            if(slow == fast ){  //means there exist a cycle in the list
                return true;
            }
        }
//         else return false
        return false;
        
    }
};