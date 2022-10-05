class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = 0; // we need this variable for making a vector of size equal to the size of highest value node
        
        for(int i=0;i<edges.size();i++){
            n = max(n,max(edges[i][0],edges[i][1])); // we do the above thing by finding out the maximum node from 2d array
        }
        
        vector<int> indegree(n+1); // make a vector of size n
        
        for(int i=0;i<edges.size();i++){  // we increase the value every time the node is visited
            indegree[edges[i][0]]++;
            indegree[edges[i][1]]++;
        }
        
        int result;
        
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==n-1){ //if any value in vector indgree matches n-1 we store its index in result 
                result = i;
                break;
            }
        }
        
        return result; // and return the result
        
    }
};