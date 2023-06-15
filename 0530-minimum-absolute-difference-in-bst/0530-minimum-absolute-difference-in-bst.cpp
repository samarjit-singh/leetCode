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
    
    vector<int> nodes;
    void inOrderTraversal(TreeNode* root){
        if(root == nullptr){
            return;
        }
        
        inOrderTraversal(root->left);
        nodes.push_back(root->val);
        inOrderTraversal(root->right);
        
    }
    int getMinimumDifference(TreeNode* root) {
        
        inOrderTraversal(root);
        
        int minDiff = abs(nodes[0]-nodes[1]);
        
        cout<<minDiff<<endl;
        
        for(int i=1;i<nodes.size();i++){
            int currDiff = abs(nodes[i]-nodes[i-1]);
            
            if(currDiff<minDiff){
                minDiff = currDiff;
            }
            
        }
        
        return minDiff;
    }
};