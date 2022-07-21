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
    ListNode* swapPairs(ListNode* head) {
        
        if(head==NULL){
            return NULL;
        }
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next;
        
        int count = 0;
        while(curr!=NULL && count<2){  //we want to run this loop only 2 times
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        
//         after this loop next will not be null it will be pointing to 3
        
            head->next = swapPairs(next);
        
        return prev;
    }
};

// time complexit is O(n)