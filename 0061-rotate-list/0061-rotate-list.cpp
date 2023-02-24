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
    
    int getListLength(ListNode* head){
        int count = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            temp = temp->next;
            count++;
        }
        return count;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        int length = getListLength(head);
        
        if(k==0 || length<=1 || k%length == 0){ // means no roration
            return head;
        }
        
        if(k>length){
            k = k%length;
        }
        
        int breakPoint = length - k;
        ListNode* temp = head;
        ListNode* prev = NULL;
        
        while(breakPoint > 0 && temp!=NULL){
            prev = temp;
            temp = temp->next;
            breakPoint--;
        }
        
        prev->next = NULL;
        ListNode* iterator = temp;
        
        if(iterator!=NULL){
            while(iterator->next!=NULL){
                iterator = iterator->next;
            }
            iterator->next = head;
        }
        
        return temp;
        
    }
};