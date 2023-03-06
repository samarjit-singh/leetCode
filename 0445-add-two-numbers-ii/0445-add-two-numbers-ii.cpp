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
    
    ListNode* reverseList(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* nextptr;
        
        while(temp!=NULL){
            nextptr = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextptr;
        }
        return prev;
    }
    
    ListNode* add(ListNode* l1,ListNode* l2){
        ListNode* dummy = new ListNode(); //creating a new node
        ListNode* temp = dummy; //temp pointing to dummy
        int carry = 0;
        
        while(l1 || l2 || carry){
            int sum = 0;
            
            if(l1){
                sum+= l1->val;
                l1 = l1->next;
            }
            
            if(l2){
                sum+= l2->val;
                l2 = l2->next;
            }
            
            sum += carry;
            carry = sum/10;
            ListNode* node = new ListNode(sum%10);
            temp->next = node;
            temp= temp->next;
        }
        
        return dummy->next;
    }
    
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1= reverseList(l1);
        l2= reverseList(l2);
        ListNode* ans= add(l1,l2);
        ans= reverseList(ans);
        return ans;
    }
};