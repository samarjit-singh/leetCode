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
    int pairSum(ListNode* head) {
        int sum = 0;
        ListNode* i = head;
        ListNode* j = head;
        int n = 0;
        
        stack<ListNode*> st;
        
        while(j!=NULL){
            n++;
            st.push(j);
            j = j->next;
        }
        
        while(st.size() > n/2){
            j = st.top();
            sum = max(sum,i->val+j->val);
            st.pop();
            i = i->next;
        }
        return sum;
    }
};