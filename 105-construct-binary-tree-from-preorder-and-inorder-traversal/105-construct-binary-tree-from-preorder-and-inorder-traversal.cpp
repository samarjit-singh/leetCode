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
    
    int PreIndex = 0; //making it global cause we want to access in the entire code
    
    TreeNode* buildTreeUtil(vector<int>& preorder, vector<int>& inorder, int inorderStart ,int inorderEnd) {
        
//         part 1
        if(inorderStart>inorderEnd){ // if inorder start is > than inorder end 
            return NULL; // return null
        }
        
//         part 2
        //make preorder first element as the root node of binary tree
        TreeNode* root = new TreeNode(preorder[PreIndex]); 
    
        PreIndex++; // and increment the size of preorder index
        
        // make a local index counter for inorder 
        // doing this beacuse we want this counter only in our sub array
        int inorderIndex;
        
//         part3
        for(int i=inorderStart; i<=inorderEnd;i++){ // start from inorder start till inorder index
            if(inorder[i]==root->val){ // if inorder ith element is = to our root val
                inorderIndex = i; //store the index value in inorder
                break; // and break from the loop
            }
        }
        
//         now its just ging to left and right
        root->left = buildTreeUtil(preorder,inorder,inorderStart,inorderIndex-1); // from to ii-1
        root->right = buildTreeUtil(preorder,inorder,inorderIndex+1,inorderEnd); // from ii+1 to ie
        
        return root; // return root
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* ans = buildTreeUtil(preorder,inorder,0,inorder.size()-1);
        return ans;
    }
};