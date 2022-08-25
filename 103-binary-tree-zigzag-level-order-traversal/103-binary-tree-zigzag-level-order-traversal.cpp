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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL){
            return{};
        }
        vector<vector<int>> result; // make a result vector
         
        queue<TreeNode*> que; // make a que to store the nodes
        
        que.push(root);  // push the root node in queue
        
        int count = 0;
        
        while(!que.empty()){ // run the while loop till the queue is not empty
            int n = que.size(); // take the size of queue
            vector<int> level_order; // make a local vector to store the node
            
            count++;
            
            for(int i=0;i<n;i++){ // run the for till the size of queue
                TreeNode* node = que.front(); // take the first node from queue
                que.pop(); // pop it from the queue
                
                if(node->left){ // if it has a left element 
                    que.push(node->left); // push it in queue
                }
                
                if(node->right){ // if it has right element 
                    que.push(node->right);//push it in queue
                }
                
                
                
                level_order.push_back(node->val); // now push the node in local vector
            }
            
            if(count%2==0){
                reverse(level_order.begin(),level_order.end());
            }
            
            result.push_back(level_order); // push the local vector in main vector
        }
        return result; // return the result
    }
};