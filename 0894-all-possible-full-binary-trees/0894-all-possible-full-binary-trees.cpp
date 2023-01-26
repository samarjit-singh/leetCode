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
    
    unordered_map<int, vector<TreeNode *>> memo;
    
    vector<TreeNode*> allPossibleFBT(int n) {
        
        vector<TreeNode *> ans; // for storing ans
        
//         If n is 0 or a multiple of 2 : in both cases, a full binary tree isn't possible, so we return empty vector.
        if(n<1 || n%2==0){
            return ans;
        }
        
//         if we have seen/stored the vector of Full Binary Trees/roots already for some n, just return that.
        if (memo.find(n) != memo.end()) {
            // memo map has something
            return memo[n];
        }
        
//         If n is 1 we return a vector with just one node with val = 0.
        if(n==1){
            ans.push_back(new TreeNode(0));
            memo[1] = ans;
            return ans;
        }
        
        for(int i=1;i<n;i+=2){
//             incremented i by 2 because if we increment it by 1 : it'll automatically get rejected by the base condition
            vector<TreeNode *> left = allPossibleFBT(i);
            vector<TreeNode *> right = allPossibleFBT(n-i-1);
            
            for(int j=0;j<left.size();j++){
                for(int k=0;k<right.size();k++){
                    TreeNode * root = new TreeNode(0);
                    root->left = left[j];
                    root->right = right[k];
                    ans.push_back(root);
                }
            }
        }
        
        memo[n] = ans; // memorize the ans for this integer
        return ans;
        
    }
};