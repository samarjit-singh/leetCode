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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *p1 = head, *p2 = head, *kth = NULL;
        
        while(k>1){
            p1 = p1->next;
            k--;
        }
        
        kth = p1;
        p1 = p1->next;
        
        while(p1 != NULL){
            p1 = p1->next;
            p2 = p2->next;
        }
        
        cout<<kth->val;
        swap(p2->val,kth->val);        
        
        return head;
        
    }
};

// so in this Q be basically move p1 till k 
// then put p1 value in k
// and move p1 by one position ahead
// now move p1 and p2 till p1 becomes NULL
// NOW SWAP P2 AND KTH