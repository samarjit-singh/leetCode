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
    ListNode* mergeNodes(ListNode* head) {
        if(head->val==0){
        head=head->next;
    }
        ListNode* temp = head;
        // vector<int> ans;
        ListNode* result = head;        
        
        
        int sum = 0;
        
        while(temp!=NULL){ // run the loop till temp is not null
            
           if(temp->val!=0){ // if temp value is not null
               sum += temp->val; // add that value to sum
               
               temp = temp->next; // move temp ahead
           } else { // else if temp value is 0
               result->val = sum;
               result->next = temp->next;
               temp=temp->next; // move temp forward
               result = temp;
               sum = 0; // make sum 0 again
               
               
           }     
            
        }
        return head;
    }
};