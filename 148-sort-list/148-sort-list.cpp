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
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         if list 1 is NULL return list 2
        if(list1 == NULL) {
            return list2;
        }
        
//         if list 2 is NULL return list 1
        if(list2 == NULL) {
            return list1;
        }
        
//         if list1 value is less than list2 value
        if(list1->val <= list2->val){
            list1->next = mergeTwoLists(list1->next,list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1,list2->next);
            return list2;
        }
        
    }
    ListNode* sortList(ListNode* head) {
        
//         base case
        if(head == NULL || head->next == NULL){
            return head;
        }
        
//         
        ListNode* temp = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL && fast->next != NULL){
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        temp->next = NULL;
        
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        
        return mergeTwoLists(l1,l2);
        
        
    }
};