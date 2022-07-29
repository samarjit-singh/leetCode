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
    vector<int> nextLargerNodes(ListNode* head) {
        int n = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            n++;
        }
        
        vector<int> result(n,0);
        
        stack<pair<int,int>> st;
        
        temp = head;
        
        for(int i=0;i<n;i++){
            
            while(!st.empty() && st.top().first < temp->val){
                result[st.top().second] = temp->val;
                st.pop();
            }
            
            st.push({temp->val,i});
            temp = temp->next;
        }
        return result;
    }
};