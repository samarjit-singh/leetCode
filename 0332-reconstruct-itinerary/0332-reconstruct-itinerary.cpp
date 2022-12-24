class Solution {
public:
    
    void dfs(unordered_map<string,multiset<string>> &adj,vector<string>& result,string s){
        while(adj[s].size()){ // while adj[s] ka size is not empty 
            // string v = adj[s].begin();
            string v = *(adj[s].begin());
            adj[s].erase(adj[s].begin());
            dfs(adj,result,v);
        }
        
        result.push_back(s);
        
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>> adj;
        
        for(auto t: tickets){
            adj[t[0]].insert(t[1]);
        }
        
        vector<string> result;
        
        dfs(adj,result,"JFK");
        
        reverse(result.begin(),result.end());
        
        return result;
        
    }
};
// in this appraoch we are make a adjacency list of all the nodes
// we are using multiset in apprach as it help us to store multiples elements
// we will call the dfs func
// while loop will run till the size of size of adjacent list of each node
// we will take the first elemnt from the list 
// pop it from the list 
// call a dfs for it
// now once we reach the end of dfs
// we will store all its element in our ans vector
// we reverse the ans vector and return it
