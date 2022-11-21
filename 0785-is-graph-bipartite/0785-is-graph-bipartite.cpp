class Solution {
public:

    bool isValid(vector<vector<int>>& graph,vector<int>& color,int currentColor,int node){
// if the node is already colored
        if(color[node]!=0){
            return color[node] == currentColor;
        }
//  else upadate color[node] with currentColor 
        color[node] = currentColor;

// check for ajjacent nodes
        for(int n:graph[node]){
            // color with red
            if(isValid(graph,color,-currentColor,n)==false){
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        // make a vector color of the size of an graph
        // initialize it with 0
        vector<int> color(graph.size(),0); 

// now run a for loop to fill the nodes with color blue and red
// we are using dfs for this
        for(int i=0;i<graph.size();i++){
            // we will initially color the graph with blue color
            // if the graph is not colored and teh color is not valid return false
            if(color[i]==0 && isValid(graph,color,1,i)==false){ 
                return false;
            }
        }

        // else retun ture
        return true;
    }
};

// 0 means not colored
// 1 means blue color
// -1 means red color