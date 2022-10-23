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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list1;
        
        while(a>1){
            
            ptr1 = ptr1->next;
            a--;
        }
        
        while(b){
            ptr2 = ptr2->next;
            b--;
        }
        
        ptr1->next = list2;
        
        while(ptr1->next){
            ptr1 = ptr1->next;
        }
        
        ptr1->next = ptr2->next;
        
        return list1;
    }
};