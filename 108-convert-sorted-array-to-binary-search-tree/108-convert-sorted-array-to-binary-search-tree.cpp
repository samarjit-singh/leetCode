/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    TreeNode* create(int l,int r, vector<int>& nums){
        if(l==r){
            return (new TreeNode(nums[l]));
        }
        if(l>r){
            return NULL;
        }
        int mid = l + (r-l)/2;
        
        TreeNode* temp = new TreeNode(nums[mid]);
        
        temp->left = create(l,mid-1,nums);
        temp->right = create(mid+1,r,nums);
        
        return temp;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        return create(l,r,nums);
    }
};