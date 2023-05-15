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
        if(head == nullptr) return head;
        
        vector<int> nums;
        
        ListNode* temp = head;
        
        while(temp!=NULL){
            nums.push_back(temp->val);
            temp = temp->next;
        }
        
        swap(nums[k-1],nums[nums.size()-k]);
        
        
        temp=head;
        int i=0;
        while(temp!=NULL){
            temp->val = nums[i];
            temp=temp->next;
            i++;
        }
        
        
        return head;
        
    }
};