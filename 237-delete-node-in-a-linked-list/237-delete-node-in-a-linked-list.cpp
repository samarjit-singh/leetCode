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
    void deleteNode(ListNode* node) {
//         made a pointer next and initialized 
//         it with the value of node->next
        ListNode* next = node->next;
//         in the node to be deleted we copied the 
//         the value of next
        node->val = next->val;
//         pointed node next to next->next
        node->next = next->next;
        
        delete next;
    }
};