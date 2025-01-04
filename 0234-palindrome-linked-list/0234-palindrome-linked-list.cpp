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
        if (!head || !head->next) return true;
        
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* prev = nullptr;
        ListNode* curr = slow;
        ListNode* next;

        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;

            curr=next;
        }

        ListNode* left = head;
        ListNode* right = prev;

        while(right){
            if(right->val != left->val){
                return false;
            }

            left = left->next;
            right = right->next;
        }
        
        return true;
    }
};