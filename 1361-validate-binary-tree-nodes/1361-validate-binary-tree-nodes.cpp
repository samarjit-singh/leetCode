class Solution {
public:
    
    bool isBinaryTreeValid(int root,vector<int>& leftChild, vector<int>& rightChild){
        vector<bool> visited(leftChild.size(),false);
        
        queue<int> nodeQueue;
        nodeQueue.push(root);
        visited[root] = true;
        
        while(!nodeQueue.empty()){
            int current = nodeQueue.front();
            nodeQueue.pop();
            
            if(leftChild[current]!=-1){
                if(visited[leftChild[current]]) // check for cycle
                    return false;
                
                nodeQueue.push(leftChild[current]);
                visited[leftChild[current]] = true;
            }
            
            if(rightChild[current] != -1){
                if(visited[rightChild[current]])
                    return false;
                
                nodeQueue.push(rightChild[current]);
                visited[rightChild[current]] = true; // mark right child as visited
            }
        }
        
        for(int i=0;i<visited.size();i++){
            if(!visited[i])
                return false;
        }
        
        return true;
        
    }
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<bool> childCount(n,false);
        
        for(auto child:leftChild){
//             check if node has a child
            if(child != -1){
                childCount[child] = true; // mark left child having a parent as true
            }
        }
        
        for(auto child:rightChild){
//             check if node has a child
            if(child != -1){
                // if(childCount[child]){ // if rightChild already has a parent
                //     return false;
                // }
                childCount[child] = true;
            }
        }
        
        int root = -1;
        for(int i=0;i<n;i++){
            if(!childCount[i]){
                if(root == -1)
                    root = i;
                else
                    return false;
            }
        }
        
        if(root == -1)
            return false; // no root fount not a valid binary tree
        
        return isBinaryTreeValid(root,leftChild,rightChild);
        
        
    }
};