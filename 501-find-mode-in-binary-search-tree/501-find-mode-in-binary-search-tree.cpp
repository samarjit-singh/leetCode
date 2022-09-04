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
    
    unordered_map<int, int> mp;
    
    void counter(TreeNode* root){
        if(root==NULL){
            return;
        }
        
        counter(root->left);
        mp[root->val]++;
        counter(root->right);
    }
    
    
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        
        int maxVal = 0;
        
        counter(root);
        
        for(auto& i: mp){
            maxVal = max(maxVal,i.second);
        }
        
        for(auto& i : mp){
            if(i.second == maxVal){
                ans.push_back(i.first);
            }
        }
        
        return ans;
    }
};