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
    bool isPalindrome(ListNode* head) {
        
        if(!head || !head->next){
            return true;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* curr = head;
        ListNode* prev = NULL;
        
        while(fast && fast->next){
            curr = slow;
            slow = slow->next;
            fast = fast->next->next;
            
            curr->next = prev;
            prev = curr;
        }
        
        if(fast) {
            slow = slow->next;
        }
        
        while(prev && prev->val == slow->val){
            prev = prev->next;
            slow = slow->next;
        }
        
        return !prev;
        
    }
};