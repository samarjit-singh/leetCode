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
// time complexity o(n)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
//         base case
        if(!head || !head->next){
            return true;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* current = head;
        ListNode* previous = NULL;
        
        while(fast && fast->next){
            current = slow;
            slow = slow->next;
            fast = fast->next->next;
            
            current->next = previous;
            previous = current;
        }
        
        if(fast) {
            slow = slow->next;
        }
        
//         we have first half reversed and second half reversed
//         1. previous is pointing to the head of first half
//         2. slow is pointing to the head of second half
        
        while(previous && previous->val == slow->val){
//             comparing values of previous and slow
            previous = previous->next;
            slow = slow->next;
        }
        
//         we just have to check whether previous is null or not
        return !previous;
    }
};