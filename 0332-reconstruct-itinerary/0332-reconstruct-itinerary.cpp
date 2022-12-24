class Solution {
public:
    
    void dfs(unordered_map<string,multiset<string>> &adj,vector<string>& result,string s){
        while(adj[s].size()){ // while adj[s] ka size is not empty 
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